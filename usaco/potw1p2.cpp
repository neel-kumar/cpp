#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
const long long maxn = 1e6+1;
long long fac[maxn], inv[maxn];

long long exp(long long x, unsigned long long y){
    //cout << "x = " << x << " y = " << y << " p = " << p << endl;
    long long res=1; x=x%mod;
    while(y>0){
        if (y&1) res= ((long long)res*x)%mod; y=y>>1; x=((long long)x*x)%mod;
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

signed main() {
	int n, m; cin >> n >> m;
    long long fact_inv_max = 1e6; // fact and inv to calculate to (maxval
    fac[0] = 1; inv[0] = 1;
    for(long long i = 1; i < fact_inv_max+1; i++)  {
        fac[i] = fac[i-1]*i%mod;
        inv[i] = exp(fac[i], mod-2);
    }
    // to use the inverse multiply
    // (fac[x]*inv[x]) %mod = 1
    // warning: multiply only one pair at a time then mod
    // calculate choose: choose(a, b) iff a >= b
    // WARNING I DIED LAST TIME: remember to use sub() instead of - for mod

	int ans = 0;
	for(int i = 1; i <= m; i++) ans += (choose(m, i-1)*exp(m-i, n-1)*(m-i+1))*(i%2?1:-1);
	cout << ans*pow(n,n-2) << endl;

    return 0;
}
