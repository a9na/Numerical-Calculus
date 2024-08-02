#include <iostream>
#include <vector>
#include <iomanip>
#include "functions.h"

// Function to display the menu
void displayMenu() {
    std::cout << "Numerical Calculus Methods\n";
    std::cout << "1. Forward Difference\n";
    std::cout << "2. Backward Difference\n";
    std::cout << "3. Central Difference\n";
    std::cout << "4. Trapezoidal Rule\n";
    std::cout << "5. Simpson's Rule\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::vector<double> x = {0, 1, 2, 3, 4, 5};
    std::vector<double> y = {0, 1, 4, 9, 16, 25}; // y = x^2

    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 6) {
            break;
        }

        int i;
        switch (choice) {
            case 1:
                std::cout << "Enter index for forward difference: ";
                std::cin >> i;
                try {
                    std::cout << "Forward Difference at index " << i << ": " << forwardDifference(x, y, i) << "\n";
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;

            case 2:
                std::cout << "Enter index for backward difference: ";
                std::cin >> i;
                try {
                    std::cout << "Backward Difference at index " << i << ": " << backwardDifference(x, y, i) << "\n";
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;

            case 3:
                std::cout << "Enter index for central difference: ";
                std::cin >> i;
                try {
                    std::cout << "Central Difference at index " << i << ": " << centralDifference(x, y, i) << "\n";
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;

            case 4:
                std::cout << "Trapezoidal Rule Integration: " << trapezoidalRule(x, y) << "\n";
                break;

            case 5:
                try {
                    std::cout << "Simpson's Rule Integration: " << simpsonsRule(x, y) << "\n";
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << "\n";
    }

    return 0;
}
