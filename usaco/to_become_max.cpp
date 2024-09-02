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
    ((cerr << args << " "), ...);
    cerr << endl;
}

int n,k;
vi a;

int f(int i, int v) {
	if(v <= a[i]) return 0;
	else if(i == n-1) return INT_MAX;
	else return v-a[i]+f(i+1, v-1);
}

bool check(int v) {
	for(int i = 0; i<n; ++i) {
		if(f(i, v) <= k) return true;
	}
	return false;
}

void solve() {
	cin >> n >> k;
	a.resize(n);
	int ma = 0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		ma = max(ma, a[i]);
	}

	int l=0, r=ma+k;
	while(l<r) {
		int mid = (l+r+1)/2;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid-1;
		}
	}
	cout << l << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
