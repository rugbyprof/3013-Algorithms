// A C++ program to find convex hull of a set of points
// Refer http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// for explanation of orientation()

// NOT DONE !!!
#include <iostream>
#include "json.hpp"

using namespace std;

using json = nlohmann::json;
 
// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10000
 
struct Point
{
        int x;
        int y;
};
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

int orientation(json p, json q, json r)
{
    int val = (q["y"] - p["y"]) * (r["x"] - q["x"]) - (q["x"] - p["x"]) * (r["y"] - q["y"]);
 
    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
 
// Prints convex hull of a set of n points.
json ConvexHull(Point points[], int n)
{
    json jpoints = json::array();

    // There must be at least 3 points
    if (n < 3)
        return;
 
    // Initialize Result
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;
 
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again
    int p = l, q;
    do
    {
        // Search for a point 'q' such that orientation(p, i, q) is
        // counterclockwise for all points 'i'
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
 
        next[p] = q; // Add q to result as a next point of p
        p = q; // Set p as q for next iteration
    }
    while (p != l);
 
    // Print Result
    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
            //cout << "(" << points[i].x << ", " << points[i].y << ")\n";
            jpoints.push_back({points[i].x,points[i].y});
    }
    return jpoints;
}

json ConvexHull(json points)
{
    json hull = json::array();

    // There must be at least 3 points
    if (points.size() < 3)
        return;
 
    // Initialize Result
    json next = json::array();
    
    for (int i = 0; i < points.size(); i++)
        next.push_back(-1);
 
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < points.size(); i++)
        if (points[i]["x"] < points[l]["x"])
            l = i;
 
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again
    int p = l, q;
    do
    {
        // Search for a point 'q' such that orientation(p, i, q) is
        // counterclockwise for all points 'i'
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
 
        next[p] = q; // Add q to result as a next point of p
        p = q; // Set p as q for next iteration
    }
    while (p != l);
 
    // Print Result
    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
            //cout << "(" << points[i].x << ", " << points[i].y << ")\n";
            jpoints.push_back({points[i].x,points[i].y});
    }
    return jpoints;
}
 