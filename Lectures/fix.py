import glob
import os,sys

files = glob.glob('*')


print(files)

for file in files:
    if not os.path.isfile(file):
        print('Renamed:', file[3:])
        os.rename(file, file[3:])




        