#include <iostream>
#include <bits/stdc++.h>
#include "BigReal.h"

using namespace std;


int main() {
    // test operator (>)
    BigReal n1  ("3.330");
    BigReal n2  ("3.330");
//    n2.valid();
//
//    if (n2.valid()){
//        cout<<"yes\n";
//    }else{
//        cout<<"No\n";
//    }

    if (n1 == n2){
        cout<<"yes\n";
    }else{
        cout<<"No\n";
    }
//    // Print the result
//    if (n1 > n2) {
//        cout << "n1 is greater than n2" << endl;
//    } else if (n2 > n1 ) {
//        cout << "n2 is greater than n1" << endl;
//    } else{
//        cout<<"n1 equal n2"<<endl;
//    }






    return 0;
}
