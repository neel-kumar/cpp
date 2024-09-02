#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const long long MAXN = 1e6+1;
map<char, long long> char2occ;//urence
stack<long long> div_factorials;
long long fac[MAXN], inv[MAXN];

long long exp(long long x, unsigned long long y, const long long p){
	//cout << "x = " << x << " y = " << y << " p = " << p << endl;
	long long res=1; x=x%p;
	while(y>0){
		if (y&1) res= ((long long)res*x)%p; y=y>>1; x=((long long)x*x)%p;
		//cout << "x = " << x << " y = " << y << " res = " << res << endl;
	}
	return res;
}

signed main() {
	//long long x, y; cin >> x >> y; cout << exp(x, y, 1e9+7) << endl;
	string s; cin >> s;
	long long n = s.size();
	for(char c : s) char2occ[c]++;
	fac[0] = 1; inv[0] = 1;
	for(long long i = 1; i < n+1; i++)  {
		fac[i] = fac[i-1]*i%MOD;
		//cout << "BALCK " << i << " = " << fac[i] << " * " << i << endl;
		inv[i] = exp(fac[i], MOD-2, MOD);
		//cout << "WHITE " << i << " = " << inv[i] << " * " <<  i << endl;
	}

	// compile to final
	long long ans = fac[n];
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for(char c : alphabet) {
		//cout << ans << " " << char2occ[c] << " " << inv[char2occ[c]] << endl;
		ans = (ans*inv[char2occ[c]]) %MOD;
	}
	cout << ans << endl;
	return 0;
}
