#include <iostream>

#include "help_functions.h"

// TODO: assign a value, the difference in distances between x_t and x_{t-1}
// that maximizes the returned probability of norm_pdf
// EXAMPLE:
//   Assign 2 to the value term
//   This is 7 - 5 = 2
float value = 2.0;

float parameter = 1.0;  // set as control parameter or observation measurement
float stdev = 1.0;      // position or observation standard deviation

int main() {
  float prob = Helpers::normpdf(value, parameter, stdev);
  std::cout << prob << std::endl;
  return 0;
}
