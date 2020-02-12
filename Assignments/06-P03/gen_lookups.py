import random
import string
import json

def randomString(stringLength=10):
    """Generate a random string of fixed length """
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(stringLength))


with open('/Users/griffin/Code/Courses/1-Current_Courses/3013-Algorithms//Resources/04-Data/dictionary_files/dict.json') as f:
    data = f.read()
    data = json.loads(data)

random.shuffle(data)

keys = []

for word in data:
    start = random.randint(0,5)
    end = random.randint(0,5)
    k = word[start:start+end]
    if len(k) > 1:
        keys.append(k)

random.shuffle(keys)

for k in keys[0:1000]:
    print(k)