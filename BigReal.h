//
// Created by Q on 10/28/2023.
//

#ifndef TASK_2_BIGREAL_H
#define TASK_2_BIGREAL_H

#include "string"
#include "iostream"

using namespace std;
<<<<<<< HEAD
=======

>>>>>>> abe53fd36022f6ffb6bbcfb59454efcec598d2f3
class BigReal
{
private:
    char sign ;
    string integer, fraction,holeReal;
    bool isValid  ;

public:
    // Constructors
    BigReal(string real);

    
    // Member functions

    BigReal(); // for result in operator +

    BigReal operator+(const BigReal& other) const;
    BigReal operator-(const BigReal& other) const;
<<<<<<< HEAD
    bool operator<(const BigReal& other) const;
    bool operator>(const BigReal& other) const;
=======
   
    bool operator<(const BigReal& other) const;
    bool  operator>(const BigReal& other) const;
>>>>>>> abe53fd36022f6ffb6bbcfb59454efcec598d2f3
    bool operator==(const BigReal& other) const;
    BigReal& operator=(const BigReal& other);

    void print ();
    bool valid ();
};






#endif //TASK_2_BIGREAL_H
