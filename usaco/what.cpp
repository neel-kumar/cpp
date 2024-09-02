#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
}

signed main() {
	#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
}

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	int t,c; cin >> t >> c;
	set<int> tar;
	for(int i = 0; i < t; i++) {
		int x; cin >> x;
		tar.insert(x);
	}

	string s; cin >> s;
	set<int> ds;
	int p=0;
	int cp[c];
	for(int i = 0; i < c; i++) {
		switch(s[i]) {
			case 'F':
				if(tar.count(p)) ds.insert(p);
				break;
			case 'R':
				p++;
				break;
			case 'L':
				p--;
				break;
		}
		cp[i]=p;
	}
	int ans = ds.size();

	int ch[c+1][5];
	set<int> used[5];
	memset(ch, 0, sizeof(ch));
	for(int i=c-1;i>=0;i--) {
		for(int j=0;j<5;j++) {
			ch[i][j] = ch[i+1][j]+(s[i]=='F' &&
					used[j].count(cp[i]+j-2)==0 && tar.count(cp[i]+j-2) && ds.count(cp[i]+j-2)==0);
			used[j].insert(cp[i]+j-2);
		}
		if(ds.count(cp[i])) ds.erase(ds.find(cp[i]));
	}

	for(int i=0;i<c;i++) {
		switch(s[i]) {
			case 'F':
				ans = max(ans, (int)ds.size()+ch[i][1]);
				ans = max(ans, (int)ds.size()+ch[i][3]);
				break;
			case 'R':
				ans = max(ans, (int)ds.size()+ch[i][0]);
				ans = max(ans, (int)ds.size()+ch[i][1]
						+(ds.count(cp[i])==0 && tar.count(cp[i]) && used[1].count(cp[i])==0)); // F
				break;
			case 'L':
				ans = max(ans, (int)ds.size()+ch[i][4]);
				ans = max(ans, (int)ds.size()+ch[i][3] // F
						+(ds.count(cp[i])==0 && tar.count(cp[i]) && used[3].count(cp[i])==0)); // F
				break;
		}
		if(tar.count(cp[i])) ds.insert(cp[i]);

		for(int j=0;j<5;j++) {
			if(used[j].count(cp[i]+j-2)) used[j].erase(used[j].find(cp[i]+j-2));
		}
	}
	cout << ans << endl;
}

