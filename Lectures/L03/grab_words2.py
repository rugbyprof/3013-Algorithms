#!/usr/local/bin/python3

from bs4 import BeautifulSoup
import requests
import os
import sys 
from time import sleep
import json



def getWords(link):
    subwords = []
    r = requests.get(base_url+href)
    soup = BeautifulSoup(r.text,"lxml")
    for li in soup.find_all("li"):
        print(li.text)
        subwords.append(li.text)

    return subwords

base_url = "https://www.manythings.org/vocabulary/lists/c/"
words = {}

with open("links.json","r") as links:
    data = links.read()

data = json.loads(data)


for link in data:
    print(base_url+link)

    null,name = link.split('=')
    print(name)
    cmd = f"wget {base_url}{link} -O ./word_files/{name}.html"
    print(cmd)
    os.system(cmd)





# r = requests.get(base_url)

# soup = BeautifulSoup(r.text,"lxml")

# links = []

# i = 0
# for a in soup.find_all("a"):
#     if 'words.php' in a['href']:
#         sleep(1)
#         key = a.text.replace(' ','_')
#         print(key)
#         words[key] = []
#         print(a['href'])
#         links.append(a['href'])
#         words[key] = getWords(a['href'])
#         i += 1

        

# data = json.dumps(words)

# with open("words.json","w") as jout:
#     jout.write(data)

# data = json.dumps(links)


