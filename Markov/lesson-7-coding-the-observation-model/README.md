# Coding the Observation Model

The final individual model we will implement is the observation model. The observation model accepts the pseudo range vector from the previous assignment, an observation vector (from vehicle sensors), and returns the observation model probability. Ultimately, we will multiply this by the motion model probability, then normalize to produce the belief state for the current time step.

The starter code below steps through each pseudo position x, calls the ```observation_model``` function and prints the results to standout. To complete this exercise fill in the ```observation_model function```.

To implement the observation_model function we must do the following for each pseudo position x:

- For each observation:
    - determine if a pseudo range vector exists for the current pseudo position x
    - if the vector exists, extract and store the minimum distance, element 0 of the sorted vector, and remove that element (so we don't re-use it). This will be passed to ```norm_pdf```
    - if the pseudo range vector does not exist, pass the maximum distance to ```norm_pdf```
    - use ```norm_pdf``` to determine the observation model probability
    - return the total probability

Expected result:

```bash
6.91501e-06
2.31973e-09
3.87434e-14
3.22163e-20
1.33373e-27
8.53381e-10
2.86277e-13
4.78132e-18
3.9758e-24
1.64596e-31
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
```
