#include <iostream>
#include "calculator.h"


struct myfunc {
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
            {"myfunc", myfunc()}
    };
    Calculator calc({}, functions);
    std::string expr = "cos(pi*e^2*(3*sin(30)))";
    std::cout << expr << " = " << calc.compute(expr) << std::endl;
    return 0;
}
