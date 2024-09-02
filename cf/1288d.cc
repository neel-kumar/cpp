#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int g[300001][8];

array<int,2> check(int x) {
	int b[(1<<m)]; memset(b, 0, sizeof(b));
	for(int i=0; i<n; i++) {
		int bm = 0;
		for(int j=0; j<m; j++)
			if(g[i][j] >= x) bm |= (1 << j);
		b[bm] = i+1;
	}

	for(int i = 0; i < (1<<m); i++) {
		for(int j = 0; j < (1<<m); j++) if(b[i] && b[j] && (i|j) == (1<<m)-1) {
			return {b[i], b[j]};
		}
	}

	return {-1, -1};
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>g[i][j];

	int l=0, r=1e9;
	while(l < r) {
		int mid = (l+r+1)/2;
		if(check(mid)[0] != -1) l = mid;
		else r = mid-1;
	}

	array<int,2> ans = check(l);
	cout << ans[0] << ' ' << ans[1] << endl;
}
