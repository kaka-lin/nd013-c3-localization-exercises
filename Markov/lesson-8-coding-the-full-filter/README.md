# Coding the Full Filter

In previous lessons we learned the basis of our filter, tried some example calculations by hand, and implemented critical steps and models for a single time step and vector of sensor observations. In this final coding exercise we will implement the entire filter using the pieces we have already developed for multiple time steps and sensor observations.

Sensor observations are provided in a 2D vector where each inner vector represents the sensor observations, in meters, at a time step.

```bash
{{1,7,12,21}, {0,6,11,20}, {5,10,19}, {4,9,18}, {3,8,17}, {2,7,16},
{1,6,15}, {0,5,14}, {4,13}, {3,12},{2,11},{1,10},{0,9},{8},{7},{6},{5},
{4},{3},{2},{1},{0}, {}, {}, {}};
```

Implement the Bayes' localization filter by first initializing priors, then doing the following within each time step:

- extract sensor observations
    - for each pseudo-position:
        - get the motion model probability
        - determine pseudo ranges
        - get the observation model probability
        - use the motion and observation model probabilities to calculate the posterior probability
    - normalize posteriors (see helpers.h for a normalization function)
    - update priors (priors --> posteriors)
