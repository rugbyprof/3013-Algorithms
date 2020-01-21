#include <math.h>

struct Position{
    double lat;
    double lon;

    Position(){
        lat = 0.0;
        lon = 0.0;
    }

    Position(double _lat,double _lon){
        lat = _lat;
        lon = _lon;
    }
};

/// @brief The usual PI/180 constant  
static const double DEG_TO_RAD = 0.017453292519943295769236907684886;  
/// @brief Earth's quatratic mean radius for WGS-84  
static const double EARTH_RADIUS_IN_METERS = 6372797.560856;  
  
/** @brief Computes the arc, in radian, between two WGS-84 positions. 
  * 
  * The result is equal to <code>Distance(from,to)/EARTH_RADIUS_IN_METERS</code> 
  *    <code>= 2*asin(sqrt(h(d/EARTH_RADIUS_IN_METERS )))</code> 
  * 
  * where:<ul> 
  *    <li>d is the distance in meters between 'from' and 'to' positions.</li> 
  *    <li>h is the haversine function: <code>h(x)=sin²(x/2)</code></li> 
  * </ul> 
  * 
  * The haversine formula gives: 
  *    <code>h(d/R) = h(from.lat-to.lat)+h(from.lon-to.lon)+cos(from.lat)*cos(to.lat)</code> 
  * 
  * @sa http://en.wikipedia.org/wiki/Law_of_haversines 
  */  
double ArcInRadians(const Position& from, const Position& to) {  
    double latitudeArc  = (from.lat - to.lat) * DEG_TO_RAD;  
    double longitudeArc = (from.lon - to.lon) * DEG_TO_RAD;  
    double latitudeH = sin(latitudeArc * 0.5);  
    latitudeH *= latitudeH;  
    double lontitudeH = sin(longitudeArc * 0.5);  
    lontitudeH *= lontitudeH;  
    double tmp = cos(from.lat*DEG_TO_RAD) * cos(to.lat*DEG_TO_RAD);  
    return 2.0 * asin(sqrt(latitudeH + tmp*lontitudeH));  
}  
  
/** @brief Computes the distance, in meters, between two WGS-84 positions. 
  * 
  * The result is equal to <code>EARTH_RADIUS_IN_METERS*ArcInRadians(from,to)</code> 
  * 
  * @sa ArcInRadians 
  */  
double DistanceInMeters(const Position& from, const Position& to) {  
    return EARTH_RADIUS_IN_METERS*ArcInRadians(from, to);  
} 