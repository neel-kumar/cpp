#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int find_newpos(int len, int pos) {
	int a = (len*2*2);
	int b = pos - (pos%a);
	int c = (len*2);
	int d = pos - (pos%c);
	int newpos;
	if(b == d) newpos = b + c;
	else newpos = b;
	return newpos;
}

int rec(int pos, int len, char let, int tot) {
	if(len == n) return tot;
	for(int i = pos; i < pos+len; i++) if(s[i] != let) tot++;
	return rec(find_newpos(len, pos), len*2, let-1, tot);
}

int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n >> s;
		if(n == 1) {
			cout << (s[0] != 'a') << endl;
			continue;
		}
		int ans = INT_MAX;
		char last_let = (char)('a'+log2(n));
		for(int i = 0; i < n; i++) {
			int tot = 0;
			if(s[i] != last_let) tot++;
			if(i%2 == 0) { if(s[i+1] != (char)(last_let-1)) tot++; }
			else { if(s[i-1] != (char)(last_let-1)) tot++; }
			ans = min(ans, rec(find_newpos(1, i), 2, (char)(last_let-2), tot));
		}
		cout << ans << endl;
	}
}
