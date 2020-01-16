import pprint 
strings = ['Epd', 'DcS', 'Fcf', 'Gco', 'Qzj', 'Wvc', 'RUC', 'ejJ', 'iwR', 'zyz']
results = {}

for string in strings:
    sum = 0
    for s in string:
        sum += ord(s)
    results[string] = (str(sum),sum%13)

pprint.pprint(results)