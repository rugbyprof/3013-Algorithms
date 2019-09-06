// This may look like C code, but it is really -*- C++ -*-
//
// Copyright Bob Friesenhahn, 1999, 2000, 2002, 2003
//
// GD/PerlMagick example using Magick++ methods.
//
// Concept and algorithms lifted from PerlMagick demo script
//
#pragma once

#include <Magick++.h>
#include <string>
#include <iostream>

using namespace std;

using namespace Magick;

/**
 * Class to help drawing graphs.
 * Required: 
 *     Magick++ installed
 */
struct drawGraph
{
    Image *image;       // image resource (canvas)
    int fontSize;       
    int strokeWidth;    // line thickness
    Color fillColor; 
    Color fontColor;
    Color strokeColor;  // line color
    int width;          // image size
    int height;

    /**
     * 
     */
    drawGraph(int w=300,int h=300, Color bg_color="white")
    {
        // Initialize ImageMagick install location for Windows
        //InitializeMagick(*argv);

        width = w;
        height = h;
        fillColor = bg_color;
        fontColor = "Black";
        strokeColor = "Black";
        strokeWidth = 1;
        int fontSize = 16;
        Geometry size = to_string(w)+"x"+to_string(h);
        int buffer = 50;

        image = new Image(size, fillColor);
    }

    void setStrokeColor(string color)
    {
        strokeColor = color;
    }

    void setStrokeWidth(int size)
    {
        strokeWidth = size;
    }

    void setFillColor(string color)
    {
        fillColor = color;
    }

    void setFontSize(int size)
    {
        fontSize = size;
    }

    void drawCircleNode(int ox, int oy, int rx = 20, int ry = 20)
    {   
        cout<<ox<<" "<<oy<<" "<<rx<<" "<<ry<<endl;
        image->draw(DrawableEllipse(ox, oy, rx, ry, 0, 360));
        image->fillColor(Color()); // Clear out fill color
    }

    void drawRectangleNode(int ox, int oy, int w = 20, int h = 20, string text = "Node")
    {
        vector<Coordinate> outline;
        vector<Drawable> drawlist;
        int tx = ox - (text.length() / 2) * (fontSize / 2);
        int ty = oy - (int)(fontSize / 2);
        string textLoc = "+" + to_string(tx) + "+" + to_string(ty);

        int left_x = ox - (int)(w / 2);
        int right_x = ox + (int)(w / 2);
        int lower_y = oy + (int)(h / 2);
        int upper_y = oy - (int)(h / 2);

        // Add polygon to list
        outline.clear();
        outline.push_back(Coordinate(left_x, upper_y));
        outline.push_back(Coordinate(left_x, lower_y));
        outline.push_back(Coordinate(right_x, lower_y));
        outline.push_back(Coordinate(right_x, upper_y));
        outline.push_back(Coordinate(left_x, upper_y));
        drawlist.push_back(DrawablePolygon(outline));
        image->strokeColor(strokeColor);
        image->fillColor(fillColor);
        image->draw(drawlist);

        image->strokeColor(Color());
        image->fillColor(fontColor);
        image->fontPointsize(fontSize);
        image->annotate(text, textLoc);
        image->fillColor(Color()); // Clear out fill color
    }

    void drawLine(int ox, int oy, int dx, int dy,string color = "Blue")
    {
        image->strokeColor(color);
        image->strokeWidth(strokeWidth);
        vector<Coordinate> line;
        vector<Drawable> drawlist;

        // Add polygon to list
        line.clear();
        line.push_back(Coordinate(ox, oy));
        line.push_back(Coordinate(dx, dy));
        drawlist.push_back(DrawablePolygon(line));
        image->strokeColor(color);
        image->draw(drawlist);
    }

    void writeImage(string fileName="out.png"){
        image->depth(8);
        image->compressType(RLECompression);
        image->write(fileName);
    }
};

