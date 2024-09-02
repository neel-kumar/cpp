#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int negs = 0, pos = 0;
		bool has_zero = false;
		vector<int> a;
		set<int> has_a;
		int n; cin >> n;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			if(x < 0) {
				negs++;
				a.push_back(x);
			} else if(x > 0) {
				pos++;
				a.push_back(x);
			} else {
				has_zero = true;
			}
			has_a.insert(x);
		}
		if(max(negs, pos) > 2) {
			cout << "NO\n";
			continue;
		}

		// brute force
		bool works = true;
		if(has_zero) a.push_back(0);
		for(int i = 0; i < (int)a.size(); i++) {
			for(int j = i+1; j < (int)a.size(); j++) {
				for(int k = j+1; k < (int)a.size(); k++) {
					if( has_a.count(a[i]+a[j]+a[k]) == 0) {
						works = false;
						break;
					}
				}
			}
		}
		cout << (works ? "YES\n" : "NO\n");
	}
	return 0;
}
