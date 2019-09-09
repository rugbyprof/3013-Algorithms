#!/usr/local/bin/python3

from bs4 import BeautifulSoup
import requests
import os
import sys 
from time import sleep
import json
import glob


def getWords(link):
    words = []
    soup = BeautifulSoup(html,"lxml")
    for li in soup.find_all("li"):
        print(li.text)
        words.append(li.text)
    return words
        

files = glob.glob("./word_files/*.html")

all_words = {}

for f in files:
    print(f)
    parts = f.split('/')
    name,ext = parts[-1].split('.')
    print(name)
    with open(f,'r') as hfile:
        html = hfile.read()
    all_words[name] = getWords(html)

print(all_words)

data = json.dumps(all_words)

with open('all_words.json','w') as json:
    json.write(data)

