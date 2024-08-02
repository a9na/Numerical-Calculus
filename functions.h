#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

// Function declarations
double forwardDifference(const std::vector<double>& x, const std::vector<double>& y, int i);
double backwardDifference(const std::vector<double>& x, const std::vector<double>& y, int i);
double centralDifference(const std::vector<double>& x, const std::vector<double>& y, int i);
double trapezoidalRule(const std::vector<double>& x, const std::vector<double>& y);
double simpsonsRule(const std::vector<double>& x, const std::vector<double>& y);

#endif
