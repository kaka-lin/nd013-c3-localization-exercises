# Coding the Motion Model

Now that we have manually calculated each step for determining the motion model probability, we will implement these steps in a function. The starter code in the editor steps through each position x, calls the `motion_model` function and prints the results to `stdout`. To complete this exercise fill in the `motion_model` function which will involve:

- For each $x_{t}$:
    - Calculate the transition probability for each potential value $x_{t-1}$
    - Calculate the discrete motion model probability by multiplying the transition model probability by the belief state (prior) for $x_{t-1}$
- Return total probability (sum) of each discrete probability

Expected result:

```bash
0     1.65867e-07
1     1.50359e-05
2     0.000507463
3     0.00650629
4     0.0333771
5     0.0772117
6     0.0981132
7     0.077719
8     0.0398834
9     0.0398834
10    0.077719
11    0.0981132
12    0.0772117
13    0.0333771
14    0.00650629
15    0.000507629
16    3.00718e-05
17    0.000507629
18    0.00650629
19    0.0333771
20    0.0772116
21    0.0980982
22    0.0772116
23    0.0333771
24    0.00650629
```
