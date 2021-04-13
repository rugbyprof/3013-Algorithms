#!/usr/local/bin/python3


class HashTable:
    """Simple implementation that hashes integers only
    """
    def __init__(self,table_size,collision_method):
        self.size = table_size
        self.collision_method = collision_method
        self.table = [-1 for x in range(self.size)]
        

    def __str__(self):
        s = ''
        for i in range(self.size):
            if self.collision_method != 'chaining':
                if self.table[i] > 0:
                    s += f"{i} {self.table[i]}\n"
                else:
                    s += f"{i} \n"
            else:
                if isinstance(self.table[i],list):
                    s += f"{i} {str(self.table[i])}\n"
                    # for k in self.table[i]:
                    #     s += f"{i} {k}->"
                else:
                    s += f"{i}\n"
        return s
        

    def chaining(self,item):
        key = item % self.size

        if not isinstance(self.table[key],list):
            self.table[key] = []

        self.table[key].append(item)

    def linear_probing(self,item):
        key = item % self.size

        while self.table[key] > 0:
            key = (key + 1) % self.size

        self.table[key] = item

    def quadratic_probing(self,item):
        probe_sequence = [item]
        i = 0
        
        key = (item % self.size) + i**2

        probe_sequence.append(key)

        while self.table[key] > 0:
            i += 1
            key = ((item % self.size) + i**2) % self.size
            probe_sequence.append(key)

        self.table[key] = item
        print(probe_sequence)


    def insert(self,item):

        if self.collision_method == 'linear_probing':
            self.linear_probing(item)
        elif self.collision_method == 'quadratic_probing':
            self.quadratic_probing(item)
        elif self.collision_method == 'chaining':
            self.chaining(item)
        else:
            print("Error: collision method unkown!")
    



if __name__=='__main__':
    nums = [8, 2, 7, 18, 15, 19, 23, 15, 20, 16]
    H1 = HashTable(13,'linear_probing')

    for n in nums:
        H1.insert(n)

    print(H1)

    H2 = HashTable(13,'quadratic_probing')

    for n in nums:
        H2.insert(n)

    print(H2)

    H3 = HashTable(13,'chaining')

    for n in nums:
        H3.insert(n)

    print(H3)