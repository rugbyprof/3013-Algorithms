from rich import print
import random

freq = {}

bad = {
    '\x00': 0,
    '\x01': 0,
    '\x02': 0,
    '\x03': 0,
    '\x04': 0,
    '\x05': 0,
    '\x06': 0,
    '\x07': 0,
    '\x08': 0,
    '\t': 0,
    '\n': 0,
    '\x0b': 0,
    '\x0c': 0,
    '\r': 0,
    '\x0e': 0,
    '\x0f': 0,
    '\x10': 0,
    '\x11': 0,
    '\x12': 0,
    '\x13': 0,
    '\x14': 0,
    '\x15': 0,
    '\x16': 0,
    '\x17': 0,
    '\x18': 0,
    '\x19': 0
}


def is_hex(s):
   try:
      int(s, 16)
      return True
   except ValueError:
      return False


def removeZeroVals():
   global freq
   remove = []
   for k, v in freq.items():
      if v == 0:
         remove.append(k)
   for k in remove:
      del freq[k]


def primeFreqTable():
   global freq
   freq = {}
   for i in range(26):
      freq[chr(i + 65)] = 0
   for i in range(10):
      freq[str(i)] = 0
   print(freq)


def readTxtFile(filename):
   global freq
   for i in range(26):
      freq[chr(i)] = 0

   with open(filename, 'r') as f:
      txt = f.read().upper()
      for i in range(len(txt)):
         letter = txt[i]
         if letter.isalnum() and not is_hex(letter):
            freq[letter] += 1
   return freq


def randomFreq():
   # {k: v for k, v in sorted(freq.items(), key=lambda item: item[1],reverse=True)}
   global freq

   used = []

   for i in range(26):
      r = random.randint(65, 90)
      while r in used:
         r = random.randint(65, 90)
      used.append(r)
      freq[chr(i + 65)] = r

   return freq


if __name__ == '__main__':
   primeFreqTable()
   readTxtFile("huck.txt")
   removeZeroVals()
   print(freq)
   primeFreqTable()
   print("\n\n")
   randomFreq()
   removeZeroVals()
   print(randomFreq())
