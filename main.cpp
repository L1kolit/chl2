#include <iostream>
#include <fstream>
#include "Lexer.h"

    using namespace std;

int main() {
    string s;
    fstream file("file");
    getline(file, s);
    vector<string> ss = lexer(s);
    
    for(int i = 0; i < ss.size(); i++) {
        cout << ss[i] << endl;
    }
    
    return 0;
}