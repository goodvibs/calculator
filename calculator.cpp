//
// Created by Vibhav Singamshetty on 9/24/22.
//

#include "calculator.h"
#include "computation.h"

Calculator::Calculator(
        const std::map<std::string, long double> &constants,
        const std::map<std::string, std::function<long double(long double)>> &functions
        ) {
    this->constants.insert(constants.begin(), constants.end());
    this->functions.insert(functions.begin(), functions.end());
}

long double Calculator::compute(const std::string &expr, char angleMode) const {

    Computation comp = Computation(expr, constants, functions);
    return comp.solve();
}
