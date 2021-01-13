#include <iostream>
#include <string>

    using namespace std;

int stringToInt(string s) {
    int rtn = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 49) rtn += 1;
        else if(s[i] == 50) rtn += 2;
        else if(s[i] == 51) rtn += 3;
        else if(s[i] == 52) rtn += 4;
        else if(s[i] == 53) rtn += 5;
        else if(s[i] == 54) rtn += 6;
        else if(s[i] == 55) rtn += 7;
        else if(s[i] == 56) rtn += 8;
        else if(s[i] == 57) rtn += 9;
        rtn *= 10;
    }
    rtn /= 10;
    return rtn;
}