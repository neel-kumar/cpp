#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
long long tree[200001];
// change max ops to sum or min if needed

long long query(int k) {
	long long q=0;
	while(k >= 1) {
		/* q = max(tree[k], q); */
		q += tree[k];
		k -= k&-k;
	}
	return q;
}

void upd(int k, long long x) {
	while(k <= N) {
		/* tree[k] = max(tree[k], x); */
		tree[k] += x;
		k += k&-k;
	}
}

void solve() {
	int n; cin>>n;
	N = n+1;
	memset(tree, 0, sizeof(tree));
	int f[n+1], a[n];
	memset(f, 0, sizeof(f));
	for(int i = 0; i<n; i++) {
		cin>>a[i];
		f[a[i]]++;
	}

	multiset<int> s;
	int ans = 0;
	for(int i=0; i<n; i++) {
		ans += i - query(a[i]);
		upd(a[i], 1LL);
	}

	for(int i=1; i<=n; i++) if(f[i]) {
		for(int j=1; j<f[i]; j++) ans += j;
	}

	cout << ans << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
