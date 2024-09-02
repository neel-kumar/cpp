#include <iostream>
#include <math.h>

using namespace std;

int f1(int n) {
    int ans = 0;
    while((n&1) != 1) {
        n = n >> 1;
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    string ans = "";
    for(int i = 0; i < n; i++) {
        ans += '0';
    }

    for(int i = 1; i < pow(2.0, n); i++) {
        cout << ans << "\n";
        if(ans[f1(i)] == '0') ans[f1(i)] = '1';
        else ans[f1(i)] = '0';
    }
    cout << ans << "\n";

    return 0;
}
