

with open("/Users/griffin/Sync/__currentCourses/3013-Algorithms/Assignments/03-P01/avlTree.hpp") as f:
    lines = f.readlines()
    
    
comment = False
commentTxt = ""
for line in lines:
    if "//" in line and "*" in line:
        if not comment:
            comment = True
            line = "/**\n"
        else:
            comment = False
            line = "*/"
    if comment:
        line = line[3:]
   
    print(line.strip())
print(len(lines))