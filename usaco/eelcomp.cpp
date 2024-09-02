#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("foo.eel");
    while(true) {
        string opp = " ";
        while(true) {
            char c; fin >> c; opp += c;
            if(opp == "string") break;
        }
        if(opp == "stromg") {

        }
    }
    return 0;
}
