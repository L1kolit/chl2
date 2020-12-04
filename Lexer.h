#include <iostream>
#include <vector>
#include "Errors.h"

    using namespace std;

vector<string> lexer(string line) {
    line += " ";
    vector<string> rtn;
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == 32) continue;
        else if(line[i] == 33) rtn.insert(rtn.end(), "!");
        else if(line[i] == 35) rtn.insert(rtn.end(), "#");
        else if(line[i] == 36) rtn.insert(rtn.end(), "$");
        else if(line[i] == 37) rtn.insert(rtn.end(), "%");
        else if(line[i] == 38) rtn.insert(rtn.end(), "&");
        else if(line[i] == 40) rtn.insert(rtn.end(), "(");
        else if(line[i] == 41) rtn.insert(rtn.end(), ")");
        else if(line[i] == 42) rtn.insert(rtn.end(), "*");
        else if(line[i] == 43) rtn.insert(rtn.end(), "+");
        else if(line[i] == 44) rtn.insert(rtn.end(), ",");
        else if(line[i] == 45) rtn.insert(rtn.end(), "-");
        else if(line[i] == 46) rtn.insert(rtn.end(), ".");
        else if(line[i] == 58) rtn.insert(rtn.end(), ":");
        else if(line[i] == 59) rtn.insert(rtn.end(), ";");
        else if(line[i] == 60) rtn.insert(rtn.end(), "<");
        else if(line[i] == 61) rtn.insert(rtn.end(), "=");
        else if(line[i] == 62) rtn.insert(rtn.end(), ">");
        else if(line[i] == 34 || line[i] == 39) {
            int quotes;
            string quotesLine = "";
            if(line[i] == 34) {
                quotes = 34;
                rtn.insert(rtn.end(), "\"");
            }
            else {
                quotes = 39;
                rtn.insert(rtn.end(), "\'");
            }
            i++;
            while(line[i] != quotes) {
                quotesLine += line[i];
                i++;
                if(i == line.length()) oneArgErr("openedQuot");
            }
            if(quotesLine != "") rtn.insert(rtn.end(), quotesLine);
            if(quotes == 34) rtn.insert(rtn.end(), "\"");
            else rtn.insert(rtn.end(), "\'");
        }
        else {
            string addWord = "";
            if(i + 1 == line.length()) addWord += line[i];
            else {
                while(i <= line.length()) {
                    addWord += line[i];
                    i++;
                    //cout << (int)line[i] << endl;
                    if(line[i] < 48 || line[i] > 57 && line[i] < 65 || line[i] > 90 && line[i] < 97 || line[i] > 122) {
                        i--;
                        break;
                    }
                }
            }
            rtn.insert(rtn.end(), addWord);
        }
    }
    return rtn;
}