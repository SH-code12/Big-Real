#include <iostream>
#include <bits/stdc++.h>
#include "BigReal.h"

using namespace std;


int main() {

    // test operator (>)
    BigReal n1  ("4.330");
    BigReal n2  ("3.330");
    // Print the result
    if (n1 > n2) {
        cout << "n1 is greater than n2" << endl;
    } else if (n2 > n1 ) {
        cout << "n2 is greater than n1" << endl;
    } else{
        cout<<"n1 equal n2"<<endl;
    }
    //----------------------------------------
     // test operator (<)
     BigReal n3  ("4.330");
    BigReal n4  ("-555.330");
    // Print the result
    if (n3 < n4) {
        cout << "n3 is smaller than n4" << endl;
    } else if (n4 < n3 ) {
        cout << "n4 is smaller than n3" << endl;
    } else{
        cout<<"n3 equal n4"<<endl;
    }
    //--------------------------------------------
    // test operator +
    BigReal num1("12.345");
    BigReal num2("0.007");

    // Perform addition
    BigReal sum = num1 + num2;

    // Print the result
    cout << "Sum = ";
    sum.print();
    //--------------------------------------------


    return 0;
}
