## Program 2 - Priority Queues
#### Due: September 30<sup>th</sup> by classtime.

### Overview

Using a binary heap as your data structure | read the [data file](./input_data.csv) and print out the order in which they would be processed. The order is based on the priority value. The larger the number | the higher the priority.

| animal_name           | longitude   | latitude    | date        | version | validated | adjustor |
| :-------------------- | :---------- | :---------- | :---------- | :------ | :-------- | :------- |
| Alligator mississippi | -8.5178319  | 40.927135   | 142118596   | 9.4     | false     | 0.74     |
| Crowned hawk-eagle    | -69.4887886 | -11.4077673 | -1968297180 | 8.5     | true      | 0.23     |
| Chipmunk least        | 39.3988465  | 51.1373971  | -135949885  | 0.3.6   | true      | 0.68     |
| Common grenadier      | -8.5944594  | 40.557917   | -370927360  | 9.1.7   | true      | 0.75     |

The ***priority*** will be calculated by doing the following:

1. `L` = length of the `animal_name` 
2. `D` = distance (`latitude`,`longitude`) is from (`33.9137`,`-98.4934`)
3. `A` = adjustor

`Priority` = `D*A/L`

Still not done....