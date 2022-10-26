//
// Created by Vibhav Singamshetty on 9/25/22.
//

#ifndef CALCULATOR_COMPUTATION_H
#define CALCULATOR_COMPUTATION_H


#include <vector>
#include <string>
#include <map>

class Computation {
public:
    explicit Computation(const std::string &expr, const std::map<std::string, long double> &constants, const std::map<std::string, std::function<long double(long double)>> &functions);
    long double solve();
private:
    const std::string &expr;
    const std::map<std::string, long double> &constants;
    const std::map<std::string, std::function<long double(long double)>> &functions;
    std::string::const_iterator i;
    std::vector<long double> nums;
    std::vector<std::string> ops;

    void operateNums();
};


#endif //CALCULATOR_COMPUTATION_H
