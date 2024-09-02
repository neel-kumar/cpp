#include <vector>
#include <map>
#include <iostream>

using namespace std;

int n, m, a, b;

int main() {
    cin >> n >> m >> a >> b;
    int ans = n*a;
    for(int i = 0; i < n; i++) {
        int rn=n-i;
        int costm = (rn/m)*b;
        if(rn % m == 0) {
            ans = min(ans, i*a+costm);
        } else {
            ans = min(ans, i*a+costm+b);
        }
    }
    cout << ans;
    return 0;
}
