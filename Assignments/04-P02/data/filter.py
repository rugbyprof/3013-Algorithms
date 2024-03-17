import json


def trimDictionary(n=10):
    newDict = {}
    with open("dictionary.json") as f:
        data = json.load(f)

    i = 1
    for key, val in data.items():
        if i % n == 0:
            newDict[key] = val
        i += 1
    return newDict


if __name__ == "__main__":
    n = 10
    newd = trimDictionary(n)

    with open(f"dictionary_{n}.json", "w") as f:
        json.dump(newd, f)
