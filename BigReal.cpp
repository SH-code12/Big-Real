//
// Created by Q on 10/28/2023.
//

#include "BigReal.h"
#include <regex>
#include <iostream>
using namespace std ;

BigReal::BigReal(string real) {
    if (regex_match(real, regex("[+-]?\\d*\\.?\\d+"))) {
        if (real[0] == '-') {
            sign = '-';
            real[0] = '0';
        }
        size_t dotPos = real.find(".");
        integer = real.substr(0, dotPos);
        fraction = real.substr(dotPos + 1, real.size() - dotPos - 1);
    }
    if (integer.size() == 0) {
        integer = "0";
    }
    if (fraction.size() == 0) {
        fraction = "0";
    }
}

void BigReal::print() {
    if (sign == '+') {
        char signToRemove = '+';
        integer.erase(remove(integer.begin(), integer.end(), signToRemove), integer.end());
        cout << integer << "." << fraction << endl;
    } else {
        cout << sign << integer << "." << fraction << endl;
    }
}


