import time
import subprocess
import os

with open("urls.sh", "w") as f:
    for i in range(9, 1500):
        f.write(
            f"curl https://api.mockaroo.com/api/f52ae350?count=1000&key=xxxxxxx  > random_person_data_{i}.json\n"
        )
