#include "functions.h"
#include <vector>
#include <stdexcept>

// Forward Difference Method
double forwardDifference(const std::vector<double>& x, const std::vector<double>& y, int i) {
    if (i >= x.size() - 1) {
        throw std::out_of_range("Index out of range for forward difference.");
    }
    return (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
}

// Backward Difference Method
double backwardDifference(const std::vector<double>& x, const std::vector<double>& y, int i) {
    if (i <= 0) {
        throw std::out_of_range("Index out of range for backward difference.");
    }
    return (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
}

// Central Difference Method
double centralDifference(const std::vector<double>& x, const std::vector<double>& y, int i) {
    if (i <= 0 || i >= x.size() - 1) {
        throw std::out_of_range("Index out of range for central difference.");
    }
    return (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1]);
}

// Trapezoidal Rule
double trapezoidalRule(const std::vector<double>& x, const std::vector<double>& y) {
    double integral = 0.0;
    for (size_t i = 0; i < x.size() - 1; ++i) {
        integral += 0.5 * (y[i] + y[i + 1]) * (x[i + 1] - x[i]);
    }
    return integral;
}

// Simpson's Rule
double simpsonsRule(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() < 3 || x.size() % 2 == 0) {
        throw std::invalid_argument("Simpson's rule requires an odd number of points.");
    }
    double integral = y[0] + y[x.size() - 1];
    for (size_t i = 1; i < x.size() - 1; ++i) {
        if (i % 2 == 0) {
            integral += 2 * y[i];
        } else {
            integral += 4 * y[i];
        }
    }
    integral *= (x[1] - x[0]) / 3.0;
    return integral;
}
