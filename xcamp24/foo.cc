#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	string s; cin>>s;
	int cnt = 0;
	int f[26] = {0};
	memset(f, 0, sizeof(f));
	for(int i = 0; i<s.size(); i++)
		f[s[i]-'a']++;

	// nineteen
	int ans = min(f['i'-'a'], (f['n'-'a']-1)/2);
	ans = min(ans, f['e'-'a']/3);
	ans = min(ans, f['t'-'a']);
	cout << ans << endl;
}
