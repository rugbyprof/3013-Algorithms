#!/usr/local/bin/python3

from rich.console import Console
from rich.table import Table
from rich import print
from rich.layout import Layout
from rich.live import Live
from time import sleep

class HashTable:
    """Simple implementation that hashes integers only
    """
    def __init__(self,table_size,collision_method):
        self.size = table_size
        self.collision_method = collision_method
        self.htable = [-1 for x in range(self.size)]

        self.console = Console()

        self.layout = Layout()

        self.layout.split_row(
            Layout(name="left"),
            Layout(name="middle"),
            Layout(name="right")
        )

        self.rtable = Table(title=self.collision_method)
        self.rtable.add_column("#",style="cyan", no_wrap=True)
        self.rtable.add_column("Value", style="magenta")

        for i in range(self.size):
            self.rtable.add_row(f"{i}", "")
        
        
        

    def __str__(self):
        s = ''
        for i in range(self.size):
            if self.collision_method != 'chaining':
                if self.htable[i] > 0:
                    s += f"{i} {self.htable[i]}\n"
                else:
                    s += f"{i} \n"
            else:
                if isinstance(self.htable[i],list):
                    s += f"{i} {str(self.htable[i])}\n"
                    # for k in self.htable[i]:
                    #     s += f"{i} {k}->"
                else:
                    s += f"{i}\n"
        return s
        

    def chaining(self,item):
        key = item % self.size

        if not isinstance(self.htable[key],list):
            self.htable[key] = []

        self.htable[key].append(item)

    def linear_probing(self,item):
        key = item % self.size

        while self.htable[key] > 0:
            key = (key + 1) % self.size

        self.htable[key] = item

    def quadratic_probing(self,item):
        probe_sequence = [item]
        i = 0
        
        key = (item % self.size) + i**2

        probe_sequence.append(key)

        while self.htable[key] > 0:
            i += 1
            key = ((item % self.size) + i**2) % self.size
            probe_sequence.append(key)

        self.htable[key] = item
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

    def print_layout(self):
        self.layout["left"].update(self.rtable)
        return self.layout

        
    
if __name__=='__main__':
    nums = [8, 2, 7, 18, 15, 19, 23, 15, 20, 16]
    H1 = HashTable(13,'linear_probing')

    #print(H1)

    H2 = HashTable(13,'quadratic_probing')

    for n in nums:
        H2.insert(n)

    #print(H2)

    H3 = HashTable(13,'chaining')

    for n in nums:
        H3.insert(n)

    with Live(H1.print_layout(), refresh_per_second=4) as live:  # update 4 times a second to feel fluid
        for row in range(12):
            for n in nums:
                H1.insert(n)
            sleep(0.4)
            

