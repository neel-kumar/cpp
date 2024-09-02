#include <iostream>
#include <math.h>

using namespace std;

int main() {
    long long n, tot = 0, ans = INT32_MAX;
    cin >> n;
    long long ap[n];
    for(int i = 0; i < n; i++) {
        cin >> ap[i];
        tot += ap[i];
    }
    for(int i = 0; i < (1<<n); i++) {
        long long w = 0;
        for(int j = 0; j < n; j++) if((i&(1<<j)) != 0) w += ap[j];
        ans = min(ans, abs(tot-w-w));
    }
    cout << ans;
}
