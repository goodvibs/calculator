//
// Created by Vibhav Singamshetty on 9/30/22.
//

#ifndef CALCULATOR_UTIL_H
#define CALCULATOR_UTIL_H


#include <map>
#include <cmath>

const std::map<char, int> BIN_OPS_PRECEDENCES = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'%', 2},
        {'^', 3},
};

template<typename T>
T applyBinOp(T a, T b, char binOp) {
    switch (binOp) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return std::pow(a, b);
        default:
            throw std::invalid_argument("received invalid value for binOp");
    }
}


#endif //CALCULATOR_UTIL_H
