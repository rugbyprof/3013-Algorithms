#pragma once

#include <math.h>
#include <cmath>
#include <iostream>
#include <limits.h>

#define earthRadiusKm 6371.0  //use this in the formulas to calc kilometers
#define earthRadiusMi 3959.0  // use this to calculate miles

using namespace std;

struct point;

/**
* Turn a latitutude in the form [0 , 180] to the form [-90 , 90]
* Param: 
*    double lat: (from 0,180)
* Returns: 
* 	 double lat: (from -90,90)
*/
double y2lat(double lat)
{
  lat = lat + 90.0;
  if (lat > 180)
  {
    lat -= 180;
  }

  return lat - 90.0;
}


/**
* Turn a longitude in the form [0 , 360] to the form [-180 , 180]
* Param: 
*    double lon: (from 0,360)
* Returns: 
* 	 double lon: (from -180,180)
*/
double x2lon(double lon)
{

  lon = lon + 180.0;
  if (lon > 360)
  {
    lon -= 360;
  }

  return lon - 180.0;
}

/**
* Turn a latitude in the form [-90 , 90] to the form [0 , 180]
* Param:
*    double lat: (value from -90,90)
* Returns:
* 	 double lat: (from 0,360)
*/
double lat2y(double lat)
{
  lat = lat + 180.0;

  if (lat > 180)
    return lat - 180;
  return abs(lat);
}

/**
* Turn a longitude in the form [-180 , 180] to the form [0 , 360]
* Param: 
*    double lon: (value from -180,180)
* Returns: 
* 	 double lon: (from 0,360)
*/
double lon2x(double lon)
{
  lon = lon + 360.0;

  if (lon > 360)
    return lon - 360;
  return abs(lon);
}

// This function converts decimal degrees to radians
double deg2rad(double deg)
{
  return (deg * M_PI / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad)
{
  return (rad * 180 / M_PI);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * Params:
 *    double lat1d Latitude of the first point in degrees
 *    double lon1d Longitude of the first point in degrees
 *    double lat2d Latitude of the second point in degrees
 *    double lon2d Longitude of the second point in degrees
 * Returns:
 *    The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d)
{
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r) / 2);
  v = sin((lon2r - lon1r) / 2);
  return 2.0 * earthRadiusMi * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

struct point
{
  double x;
  double y;

  point()
  {
    x = 0.0;
    y = 0.0;
  }

  point(double a, double b)
  {
    x = a;
    y = b;
  }

  void setXY(double ix, double iy)
  {
    x = ix;
    y = iy;
  }

  /**
     *  Scale x,y in the initial form:
     *       x in the form [0 , 360]
     *       y in the form [0 , 180]
     *  by some scaling factor.
     *  Example:
     * 
     *     scaleXY(1024,768);
     */
  void scaleXY(int width, int height)
  {
    x = (x / 360.0) * width;
    y = (y / 90.0) * height;
  }

  /**
     * operator= - overload assignment for latlon
     * Params:
     *     const latlon ll     - lat lon to assign
     * Returns 
     *     reference to assignment for chaining (e.g. a = b = c )
     */
  point &operator=(const point &p)
  {
    // do the copy
    x = p.x;
    y = p.y;

    // return the existing object so we can chain this operator
    return *this;
  }
  /**
     * operator<< - overload cout for latlon
     * Params:
     *     const latlon ll     - lat lon to print
     * Returns 
     *     formatted output for a latlon
     */
  friend ostream &operator<<(ostream &output, const point &xy)
  {
    output << "(" << xy.x << "," << xy.y << ")";
    return output;
  }
};

struct latlon
{
  double lat;
  double lon;
  double x;
  double y;

  latlon()
  {
    lat = 0.0;
    lon = 0.0;
  }

  latlon(double lt, double lg)
  {
    lat = lt;
    lon = lg;
  }

  /**
     * operator= - overload assignment for latlon
     * Params:
     *     const latlon ll     - lat lon to assign
     * Returns 
     *     reference to assignment for chaining (e.g. a = b = c )
     */
  latlon &operator=(const latlon &ll)
  {
    // do the copy
    lat = ll.lat;
    lon = ll.lon;

    // return the existing object so we can chain this operator
    return *this;
  }

  /**
     * operator<< - overload cout for latlon
     * Params:
     *     const latlon ll     - lat lon to print
     * Returns 
     *     formatted output for a latlon
     */
  friend ostream &operator<<(ostream &output, const latlon &ll)
  {
    output << "[" << ll.lat << "," << ll.lon << "]";
    return output;
  }
};

/**
 * This is a "bounding box" that updates its extremes everytime
 * a latlon is added. 
 * It maintains "top-left" and "bottom-right" points to define the "box"
 * It also keeps the center updated.
 */ 
struct llBox
{
  latlon tl_ll;
  latlon br_ll;
  latlon center;
  point c_p;
  point tl_p;
  point br_p;
  bool init;
  int minx;
  int miny;
  int maxx;
  int maxy;

  /**
   * Constructor 1
   */
  llBox()
  {
    init = false;
    minx = 99999;
    miny = 99999;
    maxx = 0;
    maxy = 0;
  }

  /**
   * Constructor 2
   */
  llBox(latlon ll1, latlon ll2)
  {
    init = true;
    tl_ll = ll1;
    br_ll = ll2;
    tl_p = point(lon2x(tl_ll.lon), lat2y(tl_ll.lat));
    br_p = point(lon2x(br_ll.lon), lat2y(br_ll.lat));
    minx = INT_MAX;
    miny = INT_MAX;
    maxx = INT_MIN;
    maxy = INT_MIN;
  }

  /**
   * Sets the init flag to false so that the next point added
   * aferword re-initializes the box.
   */
  void reset(){
    init = false;
  }
  
  /**
   * Add a latlon to the bounding box. Will be compared and if outside the 
   * existing box, edges will be updated to include it. 
   */
  void addLatLon(latlon ll)
  {
    double y = lat2y(ll.lat);
    double x = lon2x(ll.lon);

    // If init==false then initialize the bounds
    if (!init)
    {
      tl_ll = ll;
      br_ll = ll;
      tl_p = point(lon2x(ll.lon), lat2y(ll.lat));
      br_p = point(lon2x(ll.lon), lat2y(ll.lat));
      init = true;
      minx = INT_MAX;
      miny = INT_MAX;
      maxx = INT_MIN;
      maxy = INT_MIN;
    }
    else
    {
      // upper left x or lon
      if (x < tl_p.x)
      {
        tl_p.x = x;
        tl_ll.lon = ll.lon;
      }
      // upper left y or lat
      if (y > tl_p.y)
      {
        tl_p.y = y;
        tl_ll.lat = ll.lat;
      }
      // lower right x or lon
      if (x > br_p.x)
      {
        br_p.x = x;
        br_ll.lon = ll.lon;
      }
      // lower right y or lat
      if (y < br_p.y)
      {
        br_p.y = y;
        br_ll.lat = ll.lat;
      }
      if(x < minx){
        minx = x;
      }
      if(y < miny){
        miny = y;
      }
      if(x > maxx){
        maxx = x;
      }
      if(y > maxy){
        maxy = y;
      }
    }
    //calculate or re-calculate the center lat of the box
    center.lat = (abs(tl_ll.lat) + abs(br_ll.lat)) / 2;
    if (tl_ll.lat < 0 || br_ll.lat < 0)
    {
      center.lat *= -1;
    }
    //same but for lon
    center.lon = (abs(tl_ll.lon) + abs(br_ll.lon)) / 2;
    if (tl_ll.lon < 0 || br_ll.lon < 0)
    {
      center.lon *= -1;
    }

    // center point with new coords 
    c_p = point(lon2x(center.lon), lat2y(center.lat));
  }

  /**
     * operator<< - overload cout for box
     * Params:
     *     const latlon ll     - lat lon to print
     * Returns 
     *     formatted output for a latlon
     */
  friend ostream &operator<<(ostream &output, const llBox &ll)
  {
    output << "[LL(" << ll.tl_ll.lat << "," << ll.tl_ll.lon << "),(" << ll.br_ll.lat << "," << ll.br_ll.lon << ")]\n"
           << "[XY(" << ll.tl_p.y << "," << ll.tl_p.x << "),(" << ll.br_p.y << "," << ll.br_p.x << ")]\n"
           << "[Center(" << ll.center.lat << "," << ll.center.lon << "),(" << ll.c_p.y << "," << ll.c_p.x << ")]\n"
           << "[Max(" << ll.miny << "," << ll.minx << "),(" << ll.maxy << "," << ll.maxx << ")]\n";
    return output;
  }
};

/**
 * Given two floats and an int, return a 2-tuple of ints.
 * Note that the pixel coordinates are tied to the entire map, not to the map
 * section currently in view.
*/
point ll2px(double lat, double lng, int zoom)
{
  int CBK[] = {128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456};
  double CEK[] = {0.7111111, 1.42222222, 2.84444, 5.688888, 11.377777, 22.7555555, 45.51111, 91.022222, 182.0444444, 364.0888888, 728.1777777, 1456.3555555, 2912.711111, 5825.422222, 11650.844444, 23301.688888, 46603.377777, 93206.7555, 186413.51111, 372827.022222, 745654.04444, 1491308.0888};
  double CFK[] = {40.7436654, 81.48733086, 162.97466, 325.949323, 651.898646, 1303.7972938, 2607.59458761, 5215.189175, 10430.378350, 20860.756700, 41721.513401, 83443.026803, 166886.05360752725, 333772.10721, 667544.21443, 1335088.428860, 2670176.85772, 5340353.7154, 10680707.4308, 21361414.8617, 42722829.7235, 85445659.4470};

  int cbk = CBK[zoom];

  int x = cbk + (lng * CEK[zoom]);

  double foo = sin(lat * 3.14159 / 180.0);
  if (foo < -0.9999)
  {
    foo = -0.9999;
  }
  else if (foo > 0.9999)
  {
    foo = 0.9999;
  }

  int y = int(round(cbk + (0.5 * log((1 + foo) / (1 - foo)) * (-CFK[zoom]))));

  return point(x, y);
}

/**
 * Calculate a new coordinate based on start, distance and bearing
 *
 * Params:
 *     latlon start: coordinate as decimal lat/lon pair
 *     double dist:  distance in miles
 *     double brng:  bearing in degrees (compass direction)(0-360)
 * Returns:
 *     latlon destination 
 */
latlon geo_destination(latlon start, double dist, double brng)
{
  double lat1 = deg2rad(start.lat);
  double lon1 = deg2rad(start.lon);
  dist = dist / earthRadiusMi; //Earth's radius in Mi
  brng = deg2rad(brng);

  double lat2 = asin(sin(lat1) * cos(dist) + cos(lat1) * sin(dist) * cos(brng));
  double lon2 = lon1 + atan2(sin(brng) * sin(dist) * cos(lat1),
                             cos(dist) - sin(lat1) * sin(lat2));
  lon2 = fmod((lon2 + 3 * M_PI), (2 * M_PI)) - M_PI;

  return latlon(rad2deg(lat2), rad2deg(lon2));
}

/**
 * Calculate a new coordinate based on start, distance and bearing
 *
 * Params: 
 *    latlon ll1 - starting point
 *    latlon ll2 - ending point
 * Returns:
 *    double bearing in degrees (0-360)
 */
double bearing(latlon ll1, latlon ll2)
{
  double y = sin(ll2.lat - ll1.lat) * cos(ll2.lon);
  double x = cos(ll1.lon) * sin(ll2.lon) -
             sin(ll1.lon) * cos(ll2.lon) * cos(ll2.lat - ll1.lat);
  double brng = rad2deg(atan2(y, x));
  return brng;
}