//
// Created by Q on 10/28/2023.
//

#include "BigReal.h"
#include <regex>
#include <iostream>
#include <string>
using namespace std ;
// to initialize result in operator +
BigReal::BigReal() : integer("0"), fraction("0"), sign('+') {}

BigReal::BigReal(){
    holeReal= "+0.0";
    sign='+';
    integer='0';
    fraction='0';

}
BigReal::BigReal(string real)
{
    holeReal = real;
    isValid = valid(); 

    if (isValid)
    {
        sign = real[0];
        integer = real.substr(1, real.find('.')-1);
        fraction = real.substr(real.find('.') + 1, real.length());
    }
    else{
        cout<<"error not a valid bigreal\n";
    }
    
}

//-------------------------------------------------------------------------------------------------------

void BigReal::print() {
    if (sign == '+') {
        char signToRemove = '+';
        // integer.erase(remove(integer.begin(), integer.end(), signToRemove), integer.end());
        cout << integer << "." << fraction << endl;
    } else {
        cout << sign << integer << "." << fraction << endl;
    }
}

//------------------------------------------------------------------------------------

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
    if(!valid)
        return true;
    else
        return false;
}

//----------------------------------------------------------------------------------------------------

bool BigReal::operator==(const BigReal& other) const
{
    if (!isValid || !other.isValid)
    {
        return false; 
    }

    return (sign == other.sign) && (integer == other.integer) && (fraction == other.fraction);
}
//--------------------------------------------------------------------------------------------
// Function to compare  two numbers & find greatr
bool BigReal::operator>(const BigReal& other) const {
    // Check the signs

    if (sign == '+' && other.sign == '-') {
        // + > -
        return true;
    }
    else if (sign == '-' && other.sign == '+') {
        // -< +
        return false;
    }

    // compare numbers of digits of integer part , ex : num1.digit > num2.digit ---> num1 > num2

    if (integer.size() > other.integer.size()) {
        return true;
    }
    else if (integer.size() < other.integer.size()) {
        return false;
    }

    // If the integer parts have the same number of digits, compare them digit by digit
    for (size_t i = 0; i < integer.size(); ++i) {
        if (integer[i] > other.integer[i]) {
            return true;
        }
        else if (integer[i] < other.integer[i]) {
            return false;
        }
    }

    // If the integer parts are equal, compare the fractional parts digit by digit
    for (size_t i = 0; i < fraction.size() && i < other.fraction.size(); ++i) {
        if (fraction[i] > other.fraction[i]) {
            return true;
        } else if (fraction[i] < other.fraction[i]) {
            return false;
        }
    }
    // If all comparisons are equal
    return false;
}
//-----------------------------------------------------------------------------------------------
bool BigReal::operator<(const BigReal& other) const {
    if (sign == '+' && other.sign == '-') {
        return false; // This is always greater than a negative number
    } else if (sign == '-' && other.sign == '+') {
        return true; // This is always less than a positive number
    } else if (sign == '+' && other.sign == '+') {
        // Both are positive, compare integer and fractional parts
        if (integer != other.integer) {
            return integer < other.integer;
        } else if (fraction != other.fraction) {
            return fraction < other.fraction;
        } else {
            return false; // Numbers are equal
        }
    } else {
        // Both are negative, compare integer and fractional parts
        if (integer != other.integer) {
            return integer > other.integer;
        } else if (fraction != other.fraction) {
            return fraction > other.fraction;
        } else {
            return false; // Numbers are equal
        }
    }
}
//-------------------------------------------------------------------------------------------------
BigReal BigReal::operator+(const BigReal& other) const {



    // Initialize the result
    BigReal result;

    // Check if the signs are the same
    if (sign == other.sign) {
        result.sign = sign;
    }

    // Wait operator -

    // Determine the maximum length of integer and fractional parts
    int Int_Length = max(integer.size(), other.integer.size());
    int Fraction_Length = max(fraction.size(), other.fraction.size());

    // Pad zeros to make integer parts equal in length
    string paddedInt_1 = string(Int_Length - integer.size(), '0') + integer;
    string paddedInt_2 = string(Int_Length - other.integer.size(), '0') + other.integer;

    // Perform addition of integer parts
    string sum_Integer;
    int carry = 0;
    int i = Int_Length - 1;
    int j = Int_Length - 1;

    while (i >= 0 || j >= 0 || carry) {
        int num1 = (i >= 0) ? (paddedInt_1[i] - '0') : 0;
        int num2 = (j >= 0) ? (paddedInt_2[j] - '0') : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        sum_Integer = to_string(sum % 10) + sum_Integer;
        i--;
        j--;
    }
    result.integer = sum_Integer;

    // Pad zeros to make fractional parts equal in length
    string paddedFracThis = fraction + string(Fraction_Length - fraction.size(), '0');
    string paddedFracOther = other.fraction + string(Fraction_Length - other.fraction.size(), '0');

    // Perform addition of fractional parts
    string sum_Fraction;
    carry = 0;
    int k = Fraction_Length - 1;
    int l = Fraction_Length - 1;

    while (k >= 0 || l >= 0 || carry) {
        int num1 = (k >= 0) ? (paddedFracThis[k] - '0') : 0;
        int num2 = (l >= 0) ? (paddedFracOther[l] - '0') : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        sum_Fraction = std::to_string(sum % 10) + sum_Fraction;
        k--;
        l--;
    }
    result.fraction = sum_Fraction;

    return result;
}

//-----------------------------------------------------------------------------------------------
BigReal BigReal::operator=(const BigReal& other)
{
    if (this == &other) {
        return *this;
    }

    sign = other.sign;
    integer = other.integer;
    fraction = other.fraction;
    holeReal = other.holeReal;
    isValid = other.isValid;

    return *this;
}

