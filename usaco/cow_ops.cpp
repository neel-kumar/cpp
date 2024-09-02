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

	string s; cin>>s;
	int n = s.size();
	int pc[n+1]; pc[0]=0;
	int po[n+1]; po[0]=0;
	int pw[n+1]; pw[0]=0;
	for(int i=1; i<=n; i++) {
		pc[i] = pc[i-1] + (s[i-1] == 'C');
		po[i] = po[i-1] + (s[i-1] == 'O');
		pw[i] = pw[i-1] + (s[i-1] == 'W');
	}

	int q; cin>>q;
	while(q--) {
		int l,r; cin>>l>>r;
		int c = pc[r] - pc[l-1], o = po[r] - po[l-1], w = pw[r] - pw[l-1];
		if((c%2==1 && o%2==0 && w%2==0)
			|| (c%2==0 && o%2==1 && w%2==1)) cout << 'Y';
		else cout << 'N';
	}

	cout << endl;
}

