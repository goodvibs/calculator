//
// Created by Vibhav Singamshetty on 9/24/22.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H


#include <string>
#include <vector>
#include <map>
#include <cmath>

struct sin_ {
    long double operator()(long double num) {
        return std::sin(num);
    }
};

struct cos_ {
    long double operator()(long double num) {
        return std::cos(num);
    }
};

class Calculator {
public:
    explicit Calculator(
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
            {"sin", [](long double x) {
                return std::sin(x);
            }},
            {"cos", [](long double x) {
                return std::cos(x);
            }},
            {"tan", [](long double x) {
                return std::tan(x);
            }},
            {"asin", [](long double x) {
                return std::asin(x);
            }},
            {"acos", [](long double x) {
                return std::acos(x);
            }},
            {"atan", [](long double x) {
                return std::atan(x);
            }},
            {"ln", [](long double x) {
                return std::log(x);
            }},
            {"log", [](long double x) {
                return std::log10(x);
            }},
            {"sqrt", [](long double x) {
                return std::sqrt(x);
            }},
            {"cbrt", [](long double x) {
                return std::cbrt(x);
            }},
            {"ceil", [](long double x) {
                return std::ceil(x);
            }},
            {"floor", [](long double x) {
                return std::floor(x);
            }},
            {"round", [](long double x) {
                return std::lround(x);
            }},
            {"abs", [](long double x) {
                return std::abs(x);
            }},
            };
    std::vector<std::pair<std::string, long double>> history;
};


#endif //CALCULATOR_CALCULATOR_H
