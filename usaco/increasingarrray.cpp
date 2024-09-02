#include <iostream>

using namespace std;

long long n;

int main() {
    cin >> n;
    long long p = 0, ans = 0;
    for(long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if(p > x) ans += (p-x);
        else p = x;
    }

    cout << ans;

    return 0;
}
