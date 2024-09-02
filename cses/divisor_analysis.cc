#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6+1;
int inv[MAXN];

int exp(int x, unsigned int y, const int p) {
	//cout << "x = " << x << " y = " << y << " p = " << p << endl;
	int res=1; x=x%p;
	while(y>0){
		if (y&1) res= ((int)res*x)%p; y=y>>1; x=((int)x*x)%p;
		//cout << "x = " << x << " y = " << y << " res = " << res << endl;
	}
	return res;
}

void init(int invn) {
	inv[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
	}
	// to use the inverse multiply:
	// i*inv[x] %MOD = i/x
	// WARNING: multiply ONLY one pair at a time then MOD
}

signed main() {
	init(MAXN);

	int n; cin>>n;
	int x[n], k[n];
	int c=1,sum,prod=1;
	for(int i=0; i<n; i++) {
		cin>>x[i]>>k[i];
		c = (c*(k[i]+1))%MOD;
	}
	cout << c << " ";

	for(int i=0; i<n; i++) {
		prod = prod * exp(x[i], ( (c*inv[k[i]+1])%MOD * (k[i]*(k[i]+1)*inv[2])%MOD ) % MOD, MOD);
		prod = prod % MOD;
	}
	cout << prod << endl;
}
