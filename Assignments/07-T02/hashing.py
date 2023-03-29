from rich import print

# 8, 2, 5, 9, 1, 7, 3, 6, 4


linearProbeTable = {
    0:None,
    1:None,
    2:None,
    3:None,
    4:None,
    5:None,
    6:None
}

quadraticProbeTable = {
    0:None,
    1:None,
    2:None,
    3:None,
    4:None,
    5:None,
    6:None
}


chainingTable = {
    0:[],
    1:[],
    2:[],
    3:[],
    4:[],
    5:[],
    6:[],
}

values = [8, 2, 5, 9, 1, 7, 3, 6, 4]
M = 7

def tableFull(t):
    for k,v in t.items():
        if v == None:
            return False
    return True
    

def linearProbe():
    for v in values:
        h = v % M
        #print(f"v:{v} h:{h}")
        if linearProbeTable[h] == None:
            linearProbeTable[h] = v
        else:
            while linearProbeTable[h] != None:
                h = (h + 1) % M
                if tableFull(linearProbeTable):
                    print(f"table full when trying to hash: {v}")
                    return 
            linearProbeTable[h] = v
            
        
def quadraticProbe():
    
    for v in values:
        i = 0
        h = (v + pow(i,2)) % M
        #print(f"v:{v} h:{h} i:{i} pow(i,2):{pow(i,2)}")
        if quadraticProbeTable[h] == None:
            quadraticProbeTable[h] = v
        else:
            while quadraticProbeTable[h] != None:
                i+=1
                h = (v + pow(i,2)) % M
                #print(f"v:{v} h:{h} i:{i} pow(i,2):{pow(i,2)}")
                if i > 100:
                    print(f"probe sequence for {v} not finding empty slot, terminating...")
                    return
                if tableFull(quadraticProbeTable):
                    print(f"table full when trying to hash: {v}")
                    return

            quadraticProbeTable[h] = v
        

def chaining():
    for v in values:
        h = v % M
        chainingTable[h].append(v)


if __name__=='__main__':
    print("Linear Probing ......")
    print(values)
    linearProbe()
    for k,v in linearProbeTable.items():
        print(f"[{k}] => {v}")
    print("Quadratic Probing ......")
    quadraticProbe()
    for k,v in quadraticProbeTable.items():
        print(f"[{k}] => {v}")
    print("Chaining .......")
    print(values)
    chaining()
    for k,chain in chainingTable.items():
        print(f"[{k}] => {chain}")
    