#include <iostream>
#include "stdlib.h"

    using namespace std;

void oneArgErr(string err) {
    if(err == "openedQuot") cout << "Unclosed quotation mark";
    else if(err == "openedEqual") cout << "After equals there should be an assignment";
    cout << endl;
    exit(0);
}

void twoArgErr(string err, string name) {
    if(err == "badName") cout << "Invalid variable name: " << name;
    else if(err == "dExist") cout << "Undefined variable: " << name;
    else if(err == "unknownElement") cout << "Unknown element: " << name;
    cout << endl;
    exit(0);
}