# Initialize Priors Function

In this quiz we will create a function that initializes priors (initial belief state for each position on the map) given landmark positions, a position standard deviation (+/- 1.0), and the assumption that our car is parked next to a landmark.

Note that the control standard deviation represents the spread from movement (movement is the result of our control input in this case). We input a control of moving 1 step but our actual movement could be in the range of 1 +/- control standard deviation. The position standard deviation is the spread in our actual position. For example, we may believe start at a particular location, but we could be anywhere in that location +/- our position standard deviation.

Once you implement your solution in the editor on the right, you can compile and run your code with the button below, and see the results in the terminal.

Expected result:

```bash
0
0
0
0
0.111111
0.111111
0.111111
0
0
0.111111
0.111111
0.111111
0
0
0
0
0
0
0
0.111111
0.111111
0.111111
0
0
0
```
