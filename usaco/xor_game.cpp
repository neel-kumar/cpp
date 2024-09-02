#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	set<int> b;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		b.insert(x);
	}

	multiset<int> ans;
	for(int i = 0; i < n; i++) {
		for(int j : b){
			ans.insert(a[i]^j);
		}
	}
	set<int> fin;
	for(int x : ans) {
		if(ans.count(x) >= n) fin.insert(x);
	}
	cout << fin.size() << endl;
	for(int i : fin) cout << i << endl;
}
