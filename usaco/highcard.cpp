#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int E[50000];
int B[50000];

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int c;
        cin >> c;
        E[i] = c;
    }
    sort(E, E+N);
    int i = 1, e = 0, b = 0;
    while(i <= 2*N) {
        if(E[e] != i) {
            B[b] = i;
            b++;
        } else {
            e++;
        }
        i++;
    }

    int ans = 0;
    e = 0;
    for(b = 0; b < N; b++) {
        if(B[b] > E[e]) {
            ans++;
            e++;
        }
    }

    cout << ans;

    return 0;
}
