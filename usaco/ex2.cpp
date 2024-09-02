#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long A, B, C;

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
	int N; scanf("%d", &N);
	while(N--) {
		scanf("%lld %lld %lld", &A, &B, &C);
		printf("%lld\n", binpow(A, binpow(B, C, MOD-1), MOD));
	}
	return 0;
}
