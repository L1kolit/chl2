#include <iostream>
#include <fstream>
#include "Lexer.h"
//#include "helpFuncs.h"
#include "Parser.h"

    using namespace std;

int main() {
    string s;
    fstream file("file");
    getline(file, s);
    vector<string> ss = lexer(s);
    parse(ss);
    return 0;
}