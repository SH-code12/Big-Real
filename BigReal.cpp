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
bool BigReal::valid()
{
    bool onedot = false;
    bool valid = false;

    if (holeReal[0] == '-')
    {
        sign = '-';
    }
    else if (holeReal[0] == '+')
    {
        sign = '+';
    }
    else
    {
        valid = true;
    }

    for (int i = 1; i < holeReal.size(); i++)
    {
        if (valid)
        {
            cout << "not a valid big real\n";
            return false;
        }
        if (holeReal[i] == '.')
        {
            if (!onedot)
            {
                onedot = true;
                continue;
            }
            valid = true;
            continue;
        }
        else if (!(holeReal[i] >= '0' && holeReal[i] <= '9'))
        {
            valid = true;
            continue;
        }
        else if (holeReal[i] == '+' || holeReal[i] == '-')
        {
            valid = true;
            continue;
        }
    }
    // cout << "valid big real\n";
    return true;
}

bool BigReal::operator==(const BigReal& other) const
{
    if (!isValid || !other.isValid)
    {
        return false; // If either of them is invalid, they are not equal.
    }

    return (sign == other.sign) && (integer == other.integer) && (fraction == other.fraction);
}


