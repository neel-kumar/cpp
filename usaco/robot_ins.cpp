#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// pi operator+(pi a, pi b) { return {a.first + b.first, a.second + b.second}; }
// pi operator-(pi a, pi b) { return {a.first - b.first, a.second - b.second}; }

struct hsh {
	size_t operator()(const pi &p) const {
		return p.first * 239 + p.second;
	}
};

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int n;cin>>n;
	int n2=n/2;

	/* pi t;cin>>t.f>>t.s; */
	/* pi a1[n2],a2[n-n2]; */
	/* for(int i=0;i<n2;i++) cin>>a1[i].f>>a1[i].s; */
	/* for(int i=0;i<n-n2;i++) cin>>a2[i].f>>a2[i].s; */
	/* int ans[n+1]={0}; */

	pi t;
	scanf("%lld %lld",&(t.f),&(t.s));
	pi a1[n2],a2[n-n2];
	for(int i=0;i<n2;i++) scanf("%lld %lld",&(a1[i].f),&(a1[i].s));
	for(int i=0;i<n-n2;i++) scanf("%lld %lld",&(a2[i].f),&(a2[i].s));
	int ans[n+1]={0};

	// a1
	unordered_map<pi,vector<int>,hsh> m1;
	/* map<pi,vector<int>> m1; */
	for (int i = 0; i < (1 << n2); i++) {
		pi sum={0,0};
		int sb=0;
		for (int j = 0; j < n2; j++) {
			if ((i & (1 << j)) != 0) {
				sum.f+=a1[j].f;
				sum.s+=a1[j].s;
				sb++;
			}
		}
		m1[sum].push_back(sb);
	}

	// a2
	n2=n-n2;
	for (int i = 0; i < (1 << n2); i++) {
		pi sum={0,0};
		int sb=0;
		for (int j = 0; j < n2; j++) {
			if ((i & (1 << j)) != 0) {
				sum.f+=a2[j].f;
				sum.s+=a2[j].s;
				sb++;
			}
		}
		const vector<int>& tmp =  m1[{t.f-sum.f,t.s-sum.s}];
		for(const int& x : tmp) {
			ans[x+sb]++;
		}
	}

	for(int i=0;i<n;i++) cout<<ans[i+1]<<endl;
}
