#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n; cin >> n;
	string s; cin >> s;
	map<string,int> p;
	vector<string> v;

	string t=s;
	int i=0;
	while(p.count(t) == 0) {
		v.push_back(t);
		p[t] = i;
		string ne = "D12345678D";
		for(int i = 1; i < 9; i++) {
			int x = (t[i-1]=='S') + (t[i+1]=='S');
			if(x == 1) ne[i]='D';
			else ne[i]='S';
		}
		t=ne;
		i++;
	}
	int m = i-p[t]+1;
	if(n < i) cout << v[n] << endl;
	else cout << v[ (n-i)%m + p[t]] << endl;
}
