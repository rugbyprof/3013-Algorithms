#!/usr/local/bin/python3

import googlemaps
from datetime import datetime
import json

f = open("directions.json","w")

gmaps = googlemaps.Client(key='AIzaSyDlD3txM1F9LKClDj5qn0CITvMDhqLCZbQ')

my_dist = gmaps.distance_matrix('Allentown, Pennsylvania','South Gate, California')


my_dist = json.dumps(my_dist)

directions = gmaps.directions('Allentown, Pennsylvania','South Gate, California')

directions = json.dumps(directions)

f.write(my_dist)

f.write(directions)
