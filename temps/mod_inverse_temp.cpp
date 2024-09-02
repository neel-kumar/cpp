#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;
const int MAXN = 1e6+1;
int fac[MAXN], inv[MAXN];

int exp(int x, unsigned int y, const int p){
    //cout << "x = " << x << " y = " << y << " p = " << p << endl;
    int res=1; x=x%p;
    while(y>0){
        if (y&1) res= ((int)res*x)%p; y=y>>1; x=((int)x*x)%p;
        //cout << "x = " << x << " y = " << y << " res = " << res << endl;
    }
    return res;
}

signed main() {
    // can use without the factorial
    int n = 100000; // fact and inv to calculate to
    fac[0] = 1; inv[0] = 1;
    for(int i = 1; i < n+1; i++)  {
        // fac[i] = fac[i-1]*i%MOD;
        inv[i] = exp(fac[i], MOD-2, MOD);
    }
    // to use the inverse multiply
    // fac[x]*inv[x] %MOD = 1
    // WARNING: multiply ONLY one pair at a time then MOD

    return 0;
}
