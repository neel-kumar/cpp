#include <iostream>
#include <math.h>

using namespace std;

int intlog(int base, int x) {
    return (log(x) / log(base));
}

int main() {
    int n, ans = 0;
    cin >> n;
    while(n > 0) {
        n = n/5;
        ans += n;
    }
    cout << ans;

    return 0;
}
