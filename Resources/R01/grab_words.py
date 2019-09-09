#!/usr/local/bin/python3

from bs4 import BeautifulSoup
import requests
import os
import sys 
from time import sleep
import json

base_url = "https://www.manythings.org/vocabulary/lists/c/"
words = {}

def getWords(href):
    subwords = []
    r = requests.get(base_url+href)
    soup = BeautifulSoup(r.text,"lxml")
    for li in soup.find_all("li"):
        print(li.text)
        subwords.append(li.text)

    return subwords


r = requests.get(base_url)

soup = BeautifulSoup(r.text,"lxml")

links = []

i = 0
for a in soup.find_all("a"):
    if 'words.php' in a['href']:
        sleep(1)
        key = a.text.replace(' ','_')
        print(key)
        words[key] = []
        print(a['href'])
        links.append(a['href'])
        words[key] = getWords(a['href'])
        i += 1

        

data = json.dumps(words)

with open("words.json","w") as jout:
    jout.write(data)

data = json.dumps(links)

with open("links.json","w") as jout:
    jout.write(data)



# find all of the links to each category (other pages)
# they happen to be in line item (li) tags
# for li in page.find_all("li",{"class":"categories-list__item"}):
#     print(li)
#     print(li.a)
#     print(li.a['href'])
#     print("%s%s" % (url,li.a['href']))
#     sub_url = url+li.a['href']
#     sub_page = scraper.go(sub_url)

#     for sli in sub_page.find_all("li",{"class":"categories-list__item"}):
#         print(sli.a['href'])

