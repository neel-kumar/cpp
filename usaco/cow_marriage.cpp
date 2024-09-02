#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[100001];
int ap[100001][3];

bool check(int x) {
	int da[n+1];
	memset(da,0,sizeof(da));
	for(int i=0;i<x;i++) {
		da[ap[i][1]] += ap[i][0];
		da[ap[i][2]+1] -= ap[i][0];
	}
	int c=0;
	for(int i=0;i<n;i++) {
		c+=da[i];
		if(c>d[i]) return false;
	}
	return true;
}

signed main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> d[i];

	for(int i = 0; i < m; i++) {
		cin >> ap[i][0] >> ap[i][1] >> ap[i][2];
		ap[i][1]--; ap[i][2]--;
	}

	int l=0,r=m;
	while(l < r) {
		int mid=(l+r+1)/2;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	if(l == m) cout << "0\n";
	else cout << "-1\n" << l+1 << '\n';

	return 0;
}
