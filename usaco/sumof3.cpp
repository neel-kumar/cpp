#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int n, x;
vector<int> vals;
map<int, int> valset;

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        vals.push_back(a);
        valset[a] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(valset.count(x-vals[i]-vals[j]) != 0 && valset[x-vals[i]-vals[j]] != j && valset[x-vals[i]-vals[j]] != i) {
                cout << i+1 << " " << j+1 << " " << valset[x-vals[i]-vals[j]]+1 << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
