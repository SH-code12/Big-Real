//
// Created by Q on 10/28/2023.
//

#ifndef TASK_2_BIGREAL_H
#define TASK_2_BIGREAL_H

#include "string"
#include "iostream"
class BigReal
{
private:
    char sign ;
    std::string integer, fraction,holeReal;
    bool isValid = 1 ;

public:
    // Constructors
    BigReal(std::string real);

    
    // Member functions
    BigReal operator+(const BigReal& other) const;
    BigReal operator-(const BigReal& other) const;
   
    bool operator<(const BigReal& other) const;
    bool  operator>(const BigReal& other) const;
    bool operator==(const BigReal& other) const;
    void print ();
    bool valid ();
};






#endif //TASK_2_BIGREAL_H
