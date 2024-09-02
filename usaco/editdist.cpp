#include <bits/stdc++.h>
#include <utility>

using namespace std;
using ld = long double;
using ll = long long;

string a, b;
map<pair<int, int>, int> memo;

int f(int i, int j) {
    if(memo.count(make_pair(i, j)) != 0) return memo[make_pair(i, j)];
    else if(i < 0) return j+1;
    else if(j < 0) return i+1;
    else if(a[i] == b[j]) memo[make_pair(i, j)] = f(i-1, j-1);
    else memo[make_pair(i, j)] = 1+min(f(i-1, j-1), min(f(i-1, j), f(i, j-1)));
    return memo[make_pair(i, j)];
}

int main() {
    cin >> a >> b;
    memo[make_pair(-1, -1)] = 0;
    cout << f(a.length()-1, b.length()-1) << "\n";

    return 0;
}
