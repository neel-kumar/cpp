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
 *
 * priority_queue <int, vector<int>, greater<int> > pq; minheap
 */
using ld = long double;
using ll = long long;
#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t;cin>>t;
	while(t--) {
		string a,b;cin>>a>>b;
		int n=a.size();
		std::transform(a.begin(), a.end(), a.begin(),
				[](unsigned char c){ return std::tolower(c); });
		std::transform(b.begin(), b.end(), b.begin(),
				[](unsigned char c){ return std::tolower(c); });
		int mp[26]={-1};
		bool cont=false;
		for(int i=0;i<n;i++) {
			if(mp[a[i]-'a']!=-1 && mp[a[i]-'a']!=b[i]-'a') {
				cout << "-1\n";
				cont=true;
				break;
			}
			mp[a[i]-'a']=b[i]-'a';
		}
		if(cont) continue;

		bool vis[26]={0};
		int ans=0;
		for(int i=0;i<26;i++) ans+=mp[i]!=-1;
		// find number of cycles
	}
}
