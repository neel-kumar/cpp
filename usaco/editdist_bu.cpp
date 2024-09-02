#include <bits/stdc++.h>
#include <map>
#include <utility>

using namespace std;
using ld = long double;
using ll = long long;

string a, b;
//map<pair<int, int>, int> memo;
int memo[5000][5000];

int f(int i, int j) {
    if(i < 0 && j < 0) return 0;
    else if(j < 0) return i+1;
    else if(i < 0) return j+1;
    else if(memo[i][j] != 0) return memo[i][j];
    else if(a[i] == b[j]) memo[i][j] = f(i-1, j-1);
    else memo[i][j] = 1+min(f(i-1, j-1), min(f(i-1, j), f(i, j-1)));
    return memo[i][j];
}

int main() {
    cin >> a >> b;
    cout << f(a.length()-1, b.length()-1) << "\n";

    return 0;
}
