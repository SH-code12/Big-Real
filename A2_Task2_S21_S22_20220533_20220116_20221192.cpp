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
    // test operator +
    BigReal num3("12.345");
    BigReal num4("0.007");

    // Perform addition
    BigReal diff = num1 + num2;

    // Print the result
    cout << "Diff = ";
    diff.print();
    //--------------------------------------------
    // test oprator ==&=
    BigReal x("+2.45446789646");
    BigReal y("-3.8965690798");
    if(x==y){
        cout<<"x&y are equal\n";
    }else{
        cout<<"x&y are not equal\n";
    }
    x=y;
    if(x==y){
        cout<<"x&y are equal aftar = oprator\n";
    }else{
        cout<<"x&y are not equal aftar = oprator\n";
    }
    //--------------------------------------------
    // test valid function
    BigReal v("+4567.467987");
    // constractor checks if nv is valid and outputs a massge that it's not valid big real
    BigReal nv("+365487.467x.57x");
    if(v.valid()){
        cout<<" v is valid big real\n";
    }else{
        cout<<" v not valid big real\n";
    }
    if(nv.valid()){
        cout<<" nv is valid big real\n";
    }else{
        cout<<" nv not valid big real\n";
    }

    
    
    
    


    return 0;
}
