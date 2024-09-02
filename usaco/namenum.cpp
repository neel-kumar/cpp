/*
ID: n27k
TASK: namenum
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
const int dsize = 4167;
map<char, string> let2num;

string let2numf(char c) {
    int cn = c-'A';
    return to_string(cn/3 + 2);
}

string name2ser(string n) {
    string vser = "";
    for(char i : n)
        vser += let2num[i];
    return vser;
}

int main() {
    ifstream fin("namenum.in");
    ifstream tin("dict.txt");
    ofstream fout("namenum.out");

    string sernum;
    fin >> sernum;
    string abc = "ABCDEFGHIJKLMNOPRSTUVWXY";
    int c = 0;
    for(char i : abc) {
        let2num[i] = to_string(c/3 + 2);
        c++;
    }

    bool noans = true;
    for(int i = 0; i < dsize; i++) {
        string vname;
        tin >> vname;
        if(name2ser(vname) == sernum) {
            fout << vname << "\n";
            noans = false;
        }
    }
    if(noans) fout << "NONE\n";

    return 0;
}
