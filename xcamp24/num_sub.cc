#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;

signed main() {
	int n; cin>>n;
	int a=0, b=0, c=0;
	int cnt = 1;
	for(int i=0; i<n; i++) {
		char h; cin>>h;
		if(h=='a') a+=cnt, a %= MOD;
		else if(h=='b') b += a, b %= MOD;
		else if(h=='c') c += b, c %= MOD;
		else {
			c = (c*3 + b) %MOD;
			b = (b*3 + a) %MOD;
			a = (a*3 + cnt) %MOD;
			cnt = (cnt*3) %MOD;
		}
	}

	cout << c%MOD << endl;
}
