#include <iostream>

#include "help_functions.h"

// TODO: assign a value, the difference in distances between x_t and x_{t-1}
// that maximizes the returned probability of norm_pdf
//
// Assign 5.5 or 11.0
float value = 11.0;

// Assign 5.0 or 11.0
float parameter = 11.0;  // "observation measurement" or "control parameter"
float stdev = 1.0;       // position or observation standard deviation

int main() {
  float prob = Helpers::normpdf(value, parameter, stdev);
  std::cout << prob << std::endl;
  return 0;
}
