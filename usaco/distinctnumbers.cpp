#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> ns;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        ns.insert(n);
    }

    cout << ns.size();

    return 0;
}
