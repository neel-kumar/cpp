#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long a, b, c;
        const int M = 1e9 + 7;
        cin >> a >> b >> c;
        long long bc = 1;
        while(c > 0) {
            if(c % 2 == 1) {
                bc *= b;
                bc = bc%(M-1);
            }
            c /= 2;
            b *= b;
            b = b%(M-1);
        }

        long long ans = 1;
        while(bc > 0) {
            if(bc % 2 == 1) {
                ans *= a;
                ans = ans%M;
            }
            bc /= 2;
            a *= a;
            a = a%M;
        }

        cout << ans << "\n";
    }
    return 0;
}
