#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(string a, string b) { return (a+b)<(b+a); }

signed main() {
	int n; cin >> n;
	vector<string> s;
	for(int i=0;i<n;i++) {
		string a; cin>>a;
		s.push_back(a);
	}
	sort(s.begin(),s.end(),cmp);
	string s2="";
	for(auto i : s) s2+=i;
	cout << s2 << endl;
}
