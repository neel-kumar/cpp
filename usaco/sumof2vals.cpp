#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> as;
    map<int, int> val2index;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        as.push_back(a);
        val2index[a] = i+1;
    }

    for(int i = 0; i < n; i++) {
        if(val2index.count(x-as[i]) != 0 && val2index[x-as[i]] != i+1) {
            cout << i+1 << " " << val2index[x-as[i]] << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
