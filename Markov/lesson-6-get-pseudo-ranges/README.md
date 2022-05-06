# Get Pseudo Ranges

In the previous exercises we manually executed the steps for determining pseudo ranges and our observation model probability. Now let's implement a function that accepts a vector of landmark positions, a pseudo position (x), and returns a vector of sorted (ascending) pseudo ranges. Later, we will use the pseudo range vector as an input for our observation model function.

To implement the ```pseudo_range_estimator``` function we must do the following for each pseudo position x:

- For each landmark position:
    - determine the distance between each pseudo position x and each landmark position
    - if the distance is positive (landmark is forward of the pseudo position) push the distance to the pseudo range vector
    - sort the pseudo range vector in ascending order
    - return the pseudo range vector

There may be missing x values in the output. This is because not all x values have a forward landmark (positive pseudo range).

Expected result:

```bash
x: 0 5
x: 0 10
x: 0 12
x: 0 20
-----------------------
x: 1 4
x: 1 9
x: 1 11
x: 1 19
-----------------------
x: 2 3
x: 2 8
x: 2 10
x: 2 18
-----------------------
x: 3 2
x: 3 7
x: 3 9
x: 3 17
-----------------------
x: 4 1
x: 4 6
x: 4 8
x: 4 16
-----------------------
x: 5 5
x: 5 7
x: 5 15
-----------------------
x: 6 4
x: 6 6
x: 6 14
-----------------------
x: 7 3
x: 7 5
x: 7 13
-----------------------
x: 8 2
x: 8 4
x: 8 12
-----------------------
x: 9 1
x: 9 3
x: 9 11
-----------------------
x: 10 2
x: 10 10
-----------------------
x: 11 1
x: 11 9
-----------------------
x: 12 8
-----------------------
x: 13 7
-----------------------
x: 14 6
-----------------------
x: 15 5
-----------------------
x: 16 4
-----------------------
x: 17 3
-----------------------
x: 18 2
-----------------------
x: 19 1
-----------------------
```
