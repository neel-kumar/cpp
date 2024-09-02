#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int tree[200001];

int q(int k) {
	int q=0;
	while(k >= 1) {
		q = max(tree[k], q);
		k -= k&-k;
	}
	return q;
}

void add(int k, int x) {
	while(k <= n) {
		tree[k] = max(tree[k], x);
		k += k&-k;
	}
}

signed main() {
	cin>>n;
	int h[n], a[n];
	for(int i=0; i<n; i++) cin>>h[i];
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++)
		add(h[i], q(h[i]-1) + a[i]);
	cout << q(n) << endl;
}
