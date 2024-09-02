/*
ID: n27k
TASK: ride
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    ll w1 = 1, w2 = 1;
    for(int i : a) {
        w1 *= i-'A'+1;
    }
    for(int i : b) {
        w2 *= i-'A'+1;
    }
    if(w1%47 == w2%47) fout << "GO\n";
    else fout << "STAY\n";
    return 0;
}

