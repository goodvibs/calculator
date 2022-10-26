//
// Created by Vibhav Singamshetty on 9/25/22.
//

#include "computation.h"
#include "util.h"

Computation::Computation(const std::string &expr,
                         const std::map<std::string,
                         long double> &constants,
                         const std::map<std::string, std::function<long double(long double)>> &functions)
                         : expr(expr), constants(constants), functions(functions), i(expr.begin()) {}

long double Computation::solve() {
    while (i != expr.end()) {
        if (*i == ' ') { // if whitespace, proceed to next token
            ++i;
        }
        else if (std::isdigit(*i)) { // if next item is a number
            long double num = 0;
            do {
                num *= 10;
                num += *i - '0';
            } while (i++ != expr.end() && std::isdigit(*i));
            if (i != expr.end() && *i == '.') { // if number is a floating point value
                int decimalCount = 1;
                while (++i != expr.end() && std::isdigit(*i)) {
                    num += *i / std::pow(10, decimalCount++);
                }
            }
            nums.push_back(num);
        }
        else if (*i == '(') {
            ops.push_back("(");
            ++i;
        }
        else if (*i == ')') {
            while (ops.back()[0] != '(') {
                operateNums();
            }
            ops.pop_back();
            ++i;
        }
        else if (BIN_OPS_PRECEDENCES.find(*i) != BIN_OPS_PRECEDENCES.end()) { // if the current character is a binary arithmetic operator
            // if ops is empty or the precedence of the previous operator > the precedence of the current operator (i.e. * then +)
            if (!ops.empty() && ops.back()[0] != '(' && BIN_OPS_PRECEDENCES.at(ops.back()[0]) >= (*(BIN_OPS_PRECEDENCES.find(
                    *i))).second) {
                while (!ops.empty() && ops.back()[0] != '(') { // while ops is not empty
                    operateNums();
                }
            }
            ops.push_back(std::string(1, *i));
            ++i;
        }
        else {
            std::string item;
            while (i != expr.end() && std::isalnum(*i) && BIN_OPS_PRECEDENCES.find(*i) == BIN_OPS_PRECEDENCES.end()) {
                item += *i;
                ++i;
            }
            if (constants.count(item) == 1) {
                nums.push_back(constants.at(item));
            }
            else if (functions.count(item) == 1) {
                ops.push_back(item);
            }
            else {
                throw std::invalid_argument("item '" + item + "' is undefined");
            }
        }
    }
    while (!ops.empty()) { // while ops is not empty
        operateNums();
    }
    return nums.back();
}

void Computation::operateNums() {
    if (ops.back().length() == 1 && BIN_OPS_PRECEDENCES.find(ops.back()[0]) != BIN_OPS_PRECEDENCES.end()) { // if op is a binary operator
        long double b = nums.back();
        nums.pop_back();
        long double a = nums.back();
        nums.pop_back();
        nums.push_back(applyBinOp(a, b, ops.back()[0]));
        ops.pop_back();
    }
    else { // if op is a function
        std::function<long double(long double)> func = functions.at(ops.back());
        long double num = nums.back();
        nums.pop_back();
        nums.push_back(func(num));
        ops.pop_back();
    }
}