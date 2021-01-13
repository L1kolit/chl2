#include <iostream>
#include <vector>
#include "helpFuncs.h"

    using namespace std;

string mathParser(vector<string> line) {
    return line[0];
    //return "";
}


vector<string> variables[3];

int searchValue(string name) {
    for(int i = 0; i < variables[0].size(); i++) if(variables[0][i] == name) return stringToInt(variables[2][i]);
    return 0;
}

int searchId(string name) {
    for(int i = 0; i < variables[0].size(); i++) if(variables[0][i] == name) return i;
    return -1;
}

// !!!!!!!!!!!!!!!
    string currentAction = "";
    string currentVariable = "";


void parse(vector<string> lex) {
    for(int i = 0; i < lex.size(); i++) {
        if(lex[i] == "," && currentAction == "addInt") continue;
        if(currentVariable != "") {
            if(lex[i] == "=") {
                if(i + 1 != lex.size()) {
                    vector<string> req;
                    while(i + 1 != lex.size()) {
                        i++;
                        if(lex[i] == "," || lex[i] == ";") break;
                        req.insert(req.end(), lex[i]);
                    }
                    variables[2][searchId(currentVariable)] = mathParser(req);
                    i++;
                }
                else {
                    oneArgErr("openedEqual");
                }
                // Задел на матпарсер
            }
        }
        if(currentAction == "addInt") {
            variables[0].insert(variables[0].end(), lex[i]);
            variables[1].insert(variables[1].end(), "int");
            variables[2].insert(variables[2].end(), "0");
        }
        if(lex[i] == "integer") currentAction = "addInt";
        else if(searchId(lex[i]) != -1) currentVariable = lex[i];
        else {
            twoArgErr("unknownElement", lex[i]);
        }
    }
    for(int i = 0; i < variables[0].size(); i++) {
        cout << variables[0][i] << endl << variables[1][i] << endl << variables[2][i] << endl << endl;
    }
}