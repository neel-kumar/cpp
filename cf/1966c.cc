#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	set<int> s; for(int i = 0; i < n; i++) { int x; cin >> x; s.insert(x); }
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int x : s) pq.push(x);
	int prev = 0, cnt = 0;
	while(pq.size()!=0 && pq.top() == prev+1) {
		prev = pq.top();
		pq.pop();
		cnt++;
	}
	if(pq.size() == 0) {
		cout << (cnt%2 == 0 ? "Bob" : "Alice") << endl;
	} else {
		cout << (cnt%2 == 1 ? "Bob" : "Alice") << endl;
	}
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
