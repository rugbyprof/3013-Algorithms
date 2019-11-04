#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include"json.hpp"

/**
 * Thes are properties that geojson recognizes to "style" its elements
"properties": {
        // OPTIONAL: default ""
        // A title to show when this item is clicked or
        // hovered over
        "title": "A title",

        // OPTIONAL: default ""
        // A description to show when this item is clicked or
        // hovered over
        "description": "A description",

        // OPTIONAL: default "medium"
        // specify the size of the marker. sizes
        // can be different pixel sizes in different
        // implementations
        // Value must be one of
        // "small"
        // "medium"
        // "large"
        "marker-size": "medium",

        // OPTIONAL: default ""
        // a symbol to position in the center of this icon
        // if not provided or "", no symbol is overlaid
        // and only the marker is shown
        // Allowed values include
        // - Icon ID from the Maki project at http://mapbox.com/maki/
        // - An integer 0 through 9
        // - A lowercase character "a" through "z"
        "marker-symbol": "bus",

        // OPTIONAL: default "7e7e7e"
        // the marker's color
        //
        // value must follow COLOR RULES
        "marker-color": "#fff",

        // OPTIONAL: default "555555"
        // the color of a line as part of a polygon, polyline, or
        // multigeometry
        //
        // value must follow COLOR RULES
        "stroke": "#555555",

        // OPTIONAL: default 1.0
        // the opacity of the line component of a polygon, polyline, or
        // multigeometry
        //
        // value must be a floating point number greater than or equal to
        // zero and less or equal to than one
        "stroke-opacity": 1.0,

        // OPTIONAL: default 2
        // the width of the line component of a polygon, polyline, or
        // multigeometry
        //
        // value must be a floating point number greater than or equal to 0
        "stroke-width": 2,

        // OPTIONAL: default "555555"
        // the color of the interior of a polygon
        //
        // value must follow COLOR RULES
        "fill": "#555555",

        // OPTIONAL: default 0.6
        // the opacity of the interior of a polygon. implementations
        // may choose to set this to 0 for line features.
        //
        // value must be a floating point number greater than or equal to
        // zero and less or equal to than one
        "fill-opacity": 0.5
    }
*/

using namespace std;

using json = nlohmann::json;

class GeoJson{
private:
    json Collection;    // represents a geojson collection
    int FeatureId;      // unique id for each feature added (point , line , polygon)

    /**
     * AddFeature
     * 
     * Every "shape" in a geojson object is a "feature". A feature has "properties"
     * that deal with naming items and styling them. It also has "geometry" which is
     * the coordinates that are plotted on a map.
     * 
     */
    json AddFeature(string feature_type){

        json Feature;   // json object represents a "feature"

        Feature["type"] = "Feature";                        
        Feature["properties"] = {};
        Feature["geometry"] = {};
        Feature["geometry"]["type"] = feature_type;
        Feature["geometry"]["coordinates"] = json::array();

        return Feature;
    }

    void __AddLineString(json line){
        // create a new feature linestring
        json feature = AddFeature("LineString");

        // temp property to add 
        feature["properties"] = {{"name","line"}};

        feature["geometry"]["coordinates"] = line;

        // push our new feature onto our geojson features array
        Collection["features"].push_back(feature);
    }

    void __AddPolygon(json polygon){
        // create a new feature linestring
        json feature = AddFeature("Polygon");

        // temp property to add 
        feature["properties"] = {{"name","polygon"}};

        feature["geometry"]["coordinates"] = json::array();

        feature["geometry"]["coordinates"].push_back(polygon);

        // push our new feature onto our geojson features array
        Collection["features"].push_back(feature);
    }

    void __AddPolygon(int id, json polygon){

        // add to a feature 
        Collection["features"][id].push_back(polygon);
    }

public:

    /**
     * GeoJson constructor
     * 
     * Creates a geojson object using this standard:
     * https://tools.ietf.org/html/rfc7946
     * 
     * 
     */
    GeoJson(){

        Collection = {};
        Collection["type"]="FeatureCollection";
        //Collection["crs"]= {{"type", "name"},{"properties",{{"name","EPSG:3857"}}}};
        Collection["features"]= json::array();
        Collection["properties"] = {};
        FeatureId = 0;
    }

    /**
     * AddLineString
     * 
     * Description:
     * 
     *      linestring = [ [lon1,lat1], [lon2,lat2], ... ,[lonN,latN] ]
     *      In this case our linestring is a json array of [lon,lats]
     * 
     * Params:
     *      json::array()   : pair of doubles
     * 
     * Returns:
     * 
     *      return [int] : The index of this feature in the array of features (like an ID)
     */
    int AddLineString(json line){

        // Call the private AddLineString method right away 
        // since this overloaded method receives a json array already
        __AddLineString(line);
        
        // return the array index for this feature
        return Collection["features"].size()-1; 
    }           

    /**
     * AddGeoPoint
     * 
     * Params:
     * 
     *      double lon   : longitude
     *      double lat   : latitude
     * 
     * Returns:
     *      int : feature ID. FeatureID needed to add properties later where
     *            properties are things like color etc.
     */
    int AddGeoPoint(double lon,double lat){
        json feature = AddFeature("Point");

        feature["geometry"]["coordinates"].push_back(lon);
        feature["geometry"]["coordinates"].push_back(lat);

        Collection["features"].push_back(feature);
        return Collection["features"].size()-1;
    }

    int AddPolygon(json polygon,int id=-1){
        if(id > 0){
            __AddPolygon(id, polygon);
        }else{
            __AddPolygon(polygon);
        }
        return Collection["features"].size()-1; 
    }

    /**
     * AddProperty
     * 
     * Params:
     * 
     *      int    id    : the int ID of the feature you want to add properties to
     *      string key   : the key portion
     *      string value : the value portion 
     * Example:
     *      --------------------------------------------------------------------------
     *             AddProperty(featureID,"name","New York");
     *             AddProperty(featureID,"marker-color","#ff00ff");
     * 
     *      will add two key values: name=>New York and marker-color=>#ff00ff
     * 
     * Returns:
     *      void
     */
    void AddProperty(int id,string key,string val){
        Collection["features"][id]["properties"][key]=val;
    }

    /**
     * AddProperties
     * 
     * Params:
     * 
     *      int  id  : the int ID of the feature you want to add properties to
     *      json obj : a json object holding the properties key:value pairs
     * Example:
     *      --------------------------------------------------------------------------
     *      AddProperties(featureID,{{"name","New York"},{"marker-color","#ff00ff"}});
     * 
     *              will add two key values: name=>New York and marker-color=>#ff00ff
     * 
     *      --------------------------------------------------------------------------
     *      json obj = json::object();
     *      obj["name"] = "New York";
     *      obj["marker-color"] = "#ff00ff";
     *      AddProperties(featureID,obj);
     *      --------------------------------------------------------------------------
     * 
     * Returns:
     *      void
     */
    void AddProperties(int id,json obj){
        for (json::iterator it = obj.begin(); it != obj.end(); ++it) {
            Collection["features"][id]["properties"][it.key()] = it.value();
        }
    }

    void PrintJson(string filename){
        ofstream fout(filename);
        fout << std::setw(4) << Collection << std::endl;
        cout << std::setw(4) << Collection << std::endl;
    }


};