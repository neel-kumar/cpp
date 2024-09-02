#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<double> l(N);
    for(int i = 0; i < N; i++) {
        cin >> l[i];
    }

    sort(l.begin(), l.end());
    double ans = max(l[0], L-l[N-1]);
    for(int i = 0; i < N-1; i++) {
        double t = (l[i+1]-l[i])/2;
        ans = max(ans, t);
    }
    cout << fixed << ans;

    return 0;
}
