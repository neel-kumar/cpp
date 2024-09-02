/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second

bitset<1000000001> works;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;cin >> n;
	int ml=INT_MAX;
	set<int> a;
	for (int i = 0; i < n; i++) {
		int x;cin>>x;
		ml=min(ml,(int)(x/4));
		a.insert(x);
	}

	int ans=0;
	for(int i = 1; i <= ml; i++) {
		if(works[i]) continue;
		set<int> c;
		for(int j : a) {
			c.insert(j%i);
			if(c.size() > 3)  break;
		}
		if(c.size() <= 3) ans += i;
		else {
			works.set(i);
			for(int j=2;i*j<=ml;j++)
		 		works.set(i*j);
		}
	}
	cout << ans << endl;
}
