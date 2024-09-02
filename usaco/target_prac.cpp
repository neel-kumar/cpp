#include <bits/stdc++.h>
using namespace std;
/* #define int long long */
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t,c; cin >> t >> c;
	set<int> tar;
	for(int i = 0; i < t; i++) {
		int x; cin >> x;
		tar.insert(x);
	}

	string s; cin >> s;
	set<int> org;
	map<int,int> rorg;
	set<int> used[5];
	set<int> tbd[5];
	int p=0;
	for(int i = 0; i < c; i++) {
		switch(s[i]) {
			case 'F':
				if(tar.count(p) && org.count(p)==0) {
					org.insert(p);
					rorg[i]=p;
				}
				break;
			case 'R':
				p++;
				break;
			case 'L':
				p--;
				break;
		}
	}

	int ans = org.size();

	for(int i=c-1;i>=0;i--) {
		if(rorg.count(i)) {
			assert(org.find(rorg[i]) != org.end());
			org.erase(org.find(rorg[i]));
			for(int j=0;j<5;j++) {
				if(tbd[j].count(p)) {
					tbd[j].erase(tbd[j].find(p));
					used[j].insert(p);
				}
			}
		}

		p += (s[i] == 'L') ? 1 : 0;
		p += (s[i] == 'R') ? -1 : 0;
		switch(s[i]) {
			case 'F':
				// FIX: what if changing -> -1
				ans = max(ans, (int)org.size()+(int)used[1].size());
				ans = max(ans, (int)org.size()+(int)used[3].size());

				for(int j=0;j<5;j++) {
					if(tar.count(p+j-2)==0) continue;
					if(org.count(p+j-2)==0) used[j].insert(p+j-2);
					else tbd[j].insert(p+j-2);
				}
				break;
			case 'R':
				ans = max(ans, (int)org.size()+(int)used[0].size());
				ans = max(ans, (int)org.size()+(int)used[1].size()
						+(org.count(p)==0 && tar.count(p) && used[1].count(p)==0)); // F
				break;
			case 'L':
				ans = max(ans, (int)org.size()+(int)used[4].size());
				ans = max(ans, (int)org.size()+(int)used[3].size()
						+(org.count(p)==0 && tar.count(p) && used[3].count(p)==0)); // F
				break;
		}
	}

	assert(p==0);
	cout << ans << endl;
}
