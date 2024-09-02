/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
/* #define int long long */
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

int n;
vector<string> board;

int nq(int i, bitset<30> r, bitset<30> rd, bitset<30> ld) {
	if(i < 0) return 1;
	int ans = 0;
	/* cout << i << '\n' << r.to_string() << '\n' << */
	/* 	rd.to_string() << '\n' << ld.to_string() << '\n'; */
	for(int j = 0; j < n; j++) {
		if(board[i][j] == '.' && !r[j] && !rd[i+j] && !ld[i-j+n-1]) {
			r[j] = rd[i+j] = ld[i-j+n-1] = true;
			ans += nq(i-1, r,rd,ld);
			r[j] = rd[i+j] = ld[i-j+n-1] = false;
		}
	}
	return ans;
}

void solve(int i) {
	board.clear();
	board.resize(n);
	bitset<30> r,rd,ld;
	for(int i = 0; i < n; ++i)
		cin >> board[i];
	printf("Case %lld: %lld\n", i, nq(n-1, r,rd,ld));
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int i=1;
	while(true) {
		cin >> n;
		if(n == 0) break;
		solve(i++);
	}
}
