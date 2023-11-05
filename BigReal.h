//
// Created by Q on 10/28/2023.
//

#ifndef TASK_2_BIGREAL_H
#define TASK_2_BIGREAL_H

#include "string"
#include "iostream"

using namespace std;

class BigReal
{
private:
    char sign = '+' ;
    string integer, fraction,holeReal;
<<<<<<< HEAD
    bool isValid ;
=======
    bool isValid  ;
>>>>>>> e5fc73a3ca3abda4f84df17081d5d138b319d35c

public:
    // Constructors
    BigReal(string real);
    BigReal();

    
    // Member functions


    BigReal operator+(const BigReal& other) const;

    BigReal operator=(const BigReal& other);

    BigReal operator-(const BigReal& other) const;


    bool operator<(const BigReal& other) const;
    bool operator>(const BigReal& other) const;

    bool operator==(const BigReal& other) const;

    friend ostream& operator << (ostream& out, BigReal num);


    void print ();
    bool valid ();
};






#endif //TASK_2_BIGREAL_H
