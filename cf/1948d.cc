#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	string s; cin >> s;
	int ans=0;
	for(int i=s.size()/2;i>=0;i--) {
		set<int> works;
		for(int j=0;j<i;j++) {
			if(s[j]==s[j+i] || s[j]=='?' || s[j+i]=='?') works.insert(j);
		}
		if(works.size()==i) {
			cout << i*2 << endl;
			return;
		}

		for(int j=i*2;j<s.size();j++) {
			if(works.count(j-i*2)) works.erase(j-i*2);
			if(s[j-i]==s[j] || s[j-i]=='?' || s[j]=='?') works.insert(j-i);
			if(works.size()==i) {
				cout << i*2 << endl;
				return;
			}
		}
	}
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
