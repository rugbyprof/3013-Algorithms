## Program 2 - Priority Queues
#### Due: September 30<sup>th</sup> by classtime.

### Overview

Using a binary heap as your data structure | read a [data file](./animals.json) and print out the order in which they would be processed. The order is based on the priority value. The larger the number | the higher the priority.

| animal_name           | longitude   | latitude    | date        | version | validated | adjustor |
| :-------------------- | :---------- | :---------- | :---------- | :------ | :-------- | :------- |
| Alligator mississippi | -8.5178319  | 40.927135   | 142118596   | 9.4     | false     | 0.74     |
| Crowned hawk-eagle    | -69.4887886 | -11.4077673 | -1968297180 | 8.5     | true      | 0.23     |
| Chipmunk least        | 39.3988465  | 51.1373971  | -135949885  | 0.3.6   | true      | 0.68     |
| Common grenadier      | -8.5944594  | 40.557917   | -370927360  | 9.1.7   | true      | 0.75     |

#### Priority

The ***priority*** will be calculated by doing the following:

1. `L` = length of the `animal_name` 
2. `D` = distance (`latitude`,`longitude`) is from (`33.9137`,`-98.4934`)
3. `A` = adjustor
4. `V` = validated


`Bucket` = abs(date) % number_of_buckets

`Priority = (6372.8 - D) * A / L`

if `V` is `true`: invert `Priority`

#### Heap

- You will create `buckets` number of max heaps where order is based on the calculated priority as discussed above. 
- Assume a random number of `buckets` somewhere between `3-11` (inclusive) to place your animals in. 
- An animals `bucket` is chosen based on the date field: `abs(date) % number_of_buckets`. 

#### Output

- Perform a `remove_max` on each heap in succession: from heap 0 => N and print the Animals Name + Priority to an output file.
- Remove the top 5 animals from each heap.

Example:
```
Heap 0
==================
Springbuck 275.913
Toddy cat 253.893
        .
        .
        .

Heap 1
==================
Black-faced kangaroo -24.45
Meerkat cat -23.242
        .
        .
        .

Heap N
==================
Green heron 345.783
Blue peacock 334.102
        .
        .
        .
```

#### Deliverables

- Create a folder called `assignments`
- In `assignments` create a folder called `A03`
- In `A03` place your code in a file called `priority_heap.cpp`
- Name your input file `animals.json` and place that in the `A03` folder.
- A copy of your generated output.
- Name printed digitally on all items turned in.
- Comments:

```
/**
 * Name: Your Name
 * Date: The Date
 * Course: CMPS 3013
 * Program: A03
 * Description:
 *
 *      A very good description of your program and any instructions on how to run it.  
 */