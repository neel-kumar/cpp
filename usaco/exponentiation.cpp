#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int d, N;
int A, B;

long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b % 2)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int main(){
	int N; cin >> N;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &A, &B);
        printf("%lld\n", binpow(A, B, MOD));
    }
    return 0;
}

