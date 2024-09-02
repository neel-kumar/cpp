/*
ID: n27k
TASK: task
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ifstream fin("clumsy.in");
    //ifstream tin(".txt");
    ofstream fout("clumsy.out");

    int l = 0, r = 0, ans = 0;
    string in; fin >> in;
    for(char i : in) {
        if(i == ')') l++;
        else r++;
        if(l > r) {
            l--;
            r++;
            ans++;
        }
    }
    if(l != r) {
        ans += (r-l)/2;
    }
    fout << ans << "\n";

    return 0;
}
