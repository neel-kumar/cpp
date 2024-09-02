#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N; cin >> N;
    multiset<long long> fruits;
    for(long long i = 0; i < N; i++) {
        int x; cin >> x;
        fruits.insert(x);
    }
    int ans = 0;
    while(fruits.size() > 1) {
        auto a = fruits.begin();
        int x = *a;
        fruits.erase(a);
        a = fruits.begin();
        int y = *a;
        fruits.erase(a);
        ans += x+y;
        fruits.insert(x+y);
    }
    cout << ans;
    return 0;
}
