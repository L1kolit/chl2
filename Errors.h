#include <iostream>
#include "stdlib.h"

    using namespace std;

void oneArgErr(string err) {
    if(err == "openedQuot") cout << "Unclosed quotation mark";
    cout << endl;
    exit(0);
}

void twoArgErr(string err, string name) {
    if(err == "badName") cout << "Invalid variable name: " << name;
    cout << endl;
    exit(0);
}