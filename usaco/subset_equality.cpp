/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef bitset<1000000001> bs;
/*
 * bs[i]        =>  set.count(i)
 * bs.set(i)    =>  set.insert(i)
 * bs.reset(i)  =>  set.erase(i)
 * bs.count()   =>  set.size()
 */
using ld = long double;
#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	string s,t; cin>>s>>t;
	vector<pi> nuhuh;
	int fs[26]={0},ft[26]={0};
	for(char c : s) fs[c-'a']++;
	for(char c : t) ft[c-'a']++;

	for(char i = 'a'; i <= 'z'; i++) {
		for(char j = i+1; j <= 'z'; j++) {
			string st, tt;
			for(char c : s) if(c==i || c==j) st += c;
			for(char c : t) if(c==i || c==j) tt += c;
			if(st != tt)
				nuhuh.push_back({i,j});
		}
	}

	int n; cin >> n;
	while(n--) {
		string a; cin >> a;
		set<char> sa;
		for(char c : a) sa.insert(c);
		bool works=1;
		for(pi p : nuhuh) {
			if(sa.count(p.f) && sa.count(p.s)) {
				works=0;
				break;
			}
		}
		if(works) {
			int tcnt=0,scnt=0;
			for(char c : sa) tcnt+=ft[c-'a'],scnt+=fs[c-'a'];
			works = tcnt==scnt;
		}
		cout << (works ? "Y" : "N");
	}
	cout<<endl;
}
