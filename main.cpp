#include <iostream>
#include "calculator.h"
#include <cmath>

struct sin_ {
    long double operator()(long double num) {
        return std::sin(num);
    }
};

int main() {
    const std::map<std::string, long double> constants = {
            {"e", M_E},
            {"pi", M_PI}
    };
    const std::map<std::string, std::function<long double(long double)>> functions = {
            {"sin", sin_()}
    };
    Calculator calc({}, functions);
    std::string expr = "sin(pi*e^2)";
    std::cout << expr << " = " << calc.compute(expr) << std::endl;
    return 0;
}
