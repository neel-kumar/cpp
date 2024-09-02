#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	string s; cin>>s;
	string ans="";
	string curr="";
	int cnt=0;
	int i = 0;
	bool first = 1;
	while(i	< s.size()) {
		i = s.find("-");
		string x = s.substr(0,i);
		if(first) {
			curr = x;
		} else {
			if(x == "org") ans += curr + ' ';
			else ans += x[0] + curr + ' ';
		}
		s.erase(0,i+1);
		first = !first;
	}
	cout << ans << endl;
}
