//
// Created by Q on 10/28/2023.
//

#ifndef TASK_2_BIGREAL_H
#define TASK_2_BIGREAL_H

#include "string"
#include "iostream"
class BigReal {
public:
    // Constructors
    BigReal(string real);

    
    // Member functions
    BigReal operator+(const BigReal& other) const;
    BigReal operator-(const BigReal& other) const;
    BigReal operator<(const BigReal& other) const;
    BigReal operator>(const BigReal& other) const;
    void print ();
    
private:
    char sign = '+';
    string integer, fraction;


};






#endif //TASK_2_BIGREAL_H
