//
// Created by Vibhav Singamshetty on 9/24/22.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H


#include <string>
#include <vector>
#include <map>
#include <cmath>

class Calculator {
public:
    Calculator(
            const std::map<std::string, long double> &constants = {},
            const std::map<std::string, std::function<long double(long double)>> &functions = {}
            );
    long double compute(const std::string& expr, char angleMode = 'r') const;

private:
    std::map<std::string, long double> constants = {
            {"e", M_E},
            {"pi", M_PI}
    };
    std::map<std::string, std::function<long double(long double)>> functions = {

    };
    std::vector<std::pair<std::string, long double>> history;
};


#endif //CALCULATOR_CALCULATOR_H
