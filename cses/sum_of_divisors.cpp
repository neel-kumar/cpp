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

const int MOD=1e9+7;
const int MV=1e12;
vi primes;
/* bitset<MV> ps; */
bool ps[MV];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */
	for (int p = 2; p * p <= MV; p++) {
		if (!ps[p]) {
			primes.push_back(p);
			for (int i = p * p; i <= MV; i += p)
				ps[i]=1;
		}
	}
	cout << primes.size() << endl;

	int x;cin>>x;
	int ans=(x*(x+1)/2)%MOD;
	ans%=MOD;
	for(int i=1;i<=x;i++) {
		ans += i*((int)(x/i)-1);
		ans%=MOD;
	}
	cout<<ans<<endl;
}
