#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

signed main() {
	int n; cin >> n;
	int a[N+1] = {0};
	int ans=1;
	for(int i=0; i<n; i++) {
		int x; cin >> x;
		for(int j=1; j*j<=x; j++) {
			if(x%j==0) {
				a[j]++;
				if(a[j]>1) ans = max(ans, j);
				if(j*j!=x) a[x/j]++;
				if(a[x/j]>1) ans = max(ans, x/j);
			}
		}
	}
	cout << ans << '\n';
}
