#include <bits/stdc++.h>
#define int long long
using namespace std;

bool works(double avg) {
	priority_queue<int, vector<int>, greater<int>> pq;
	queue<int> q;
	q.push(0);
	int i = 0;
	int c = 0;
	for(; i < k-1; i++) {
		c += a[i];
		q.push(c);
	}

	int ans = INT_MIN;
	for(; i < n; i++) {
		cout << q.front() << ':';
		pq.push(q.front()); q.pop();
		c += a[i];
		cout << c << ':';
		cout << pq.top() << ' ';
		ans = max(ans, c - pq.top());
		q.push(c);
	}
	cout << endl;
}

signed main() {
	int n, k; cin >> n >> k;
	int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

	double l = 0.0, r = (double)INT_MAX;
	while(r-l > 1e-4) {
		double m = (l+r)/2.0;
		if(works(m)) {
		} else {
		}
	}
	cout << l << endl;
}
