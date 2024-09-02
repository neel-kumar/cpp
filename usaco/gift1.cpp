/*
ID: neelbaja
TASK: gift1
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    vector<string> ppl;
    map<string, int> money;
    int NP;
    fin >> NP;
    for(int i = 0; i < NP; i++) {
        string p;
        fin >> p;
        ppl.push_back(p);
        money[p] = 0;
    }
    for(int i = 0; i < NP; i++) {
        string p;
        int gm, to;
        fin >> p >> gm >> to;
        if(gm == 0 || to == 0) continue;
        int mpp = gm/to;
        for(int j = 0; j < to; j++) {
            string man;
            fin >> man;
            money[man] += mpp;
            money[p] -= mpp;
        }
    }
    for(string s : ppl) {
        fout << s << " " << money[s] << "\n";
    }
    return 0;
}

