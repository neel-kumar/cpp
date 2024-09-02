#include <bits/stdc++.h>
using namespace std;

string solve(int ain, string sn) {
	int n = ain;
	string s = sn;
	map<string,int> p;
	vector<string> v;

	string t=s;
	int i=0;
	while(p.count(t) == 0) {
		v.push_back(t);
		p[t] = i;
		string n = "D12345678D";
		for(int i = 1; i < 9; i++) {
			int x = (t[i-1]=='S') + (t[i+1]=='S');
			if(x == 1) n[i]='D';
			else n[i]='S';
		}
		t=n;
		i++;
	}
	int m = i-p[t];
	if(n < i) return v[n];
	else return v[ (n-i)%m + p[t]];
}

string verif(int ain, string sn) {
	int n = ain;
	string s = sn;
	for(int i = 0; i < n; i++) {
		string n = "D12345678D";
		for(int i = 1; i < 9; i++) {
			int x = (s[i-1]=='S') + (s[i+1]=='S');
			if(x == 1) n[i]='D';
			else n[i]='S';
		}
		s=n;
	}
	return s;
}


signed main() {
	int n; cin >> n;
	string s; cin >> s;
	cout << solve(n, s) << endl;
	return 0;

	for(int mask=0; mask<(1<<10); mask++){
		string sn = "0123456789";
		for(int bit=0;bit<10;bit++){
			bool biton = (1<<bit) & mask;
			if(biton) sn[bit] = 'D';
			else sn[bit] = 'S';
		}
		if(solve(n, sn) != verif(n, sn)) cout << sn << endl;
	}
}
