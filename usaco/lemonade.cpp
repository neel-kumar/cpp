#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> cs;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cs.push_back(x);
    }

    sort(cs.begin(), cs.end());

    int j = 0;
    for(int i = N-1; i >= 0; i--) {
        // if(N-i-2 > cs[i]) {
        if(j > cs.at(i)) {
           // cout << N-i-2;
           cout << j;
           return 0;
        }
        ++j;
    }
    cout << j;
    return 0;
}
