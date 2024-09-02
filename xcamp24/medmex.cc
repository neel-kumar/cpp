#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
const long long maxn = 1e6+1;
long long fac[maxn], inv[maxn];

long long exp(long long x, unsigned long long y, const long long p){
	//cout << "x = " << x << " y = " << y << " p = " << p << endl;
	long long res=1; x=x%p;
	while(y>0){
		if (y&1) res= ((long long)res*x)%p; y=y>>1; x=((long long)x*x)%p;
		//cout << "x = " << x << " y = " << y << " res = " << res << endl;
	}
	return res;
}

long long choose(long long a, long long b) {
	long long ans = (fac[a] * inv[b]) %mod;
	ans = (ans * inv[a-b]) %mod;
	return ans;
}

int sub(int x, int y) {
	return (x+ (mod - y))%mod;
}

void solve() {
	int n; cin>>n;

	if(n == 2) {
		cout << "0 0" << endl;
		return;
	} else if(n == 1) {
		cout << "0" << endl;
		return;
	}

	cout << "0 ";
	for(int i=2; i<=n; i++) {
		if(i-1 <= n-i) {
			int amt = 2*(i-1);
			int ans = (n-amt+mod+1)%mod;
			ans = (ans * fac[n-amt]) %mod;
			ans = (ans * fac[amt]) %mod;
			cout << ans << " ";
		} else {
			cout << "0 ";
		}
	}
	cout << endl;
}

signed main() {
	long long fact_inv_max = 1e5; // fact and inv to calculate to (maxval
	fac[0] = 1; inv[0] = 1;
	for(long long i = 1; i < fact_inv_max+1; i++) {
		fac[i] = fac[i-1]*i%mod;
		inv[i] = exp(fac[i], mod-2, mod);
	}
	// to use the inverse multiply
	// (fac[x]*inv[x]) %mod = 1
	// warning: multiply only one pair at a time then mod
	// calculate choose: choose(a, b) iff a >= b
	// WARNING I DIED LAST TIME: remember to use sub() instead of - for mod

	int testcases; cin >> testcases; while(testcases--) solve();
}
