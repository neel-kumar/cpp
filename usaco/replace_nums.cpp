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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int q; cin >> q;
	int t[q], x[q], y[q];
	for(int i = 0; i < q; i++) {
		cin >> t[i] >> x[i];
		if(t[i] == 2) cin >> y[i];
	}
	int p[500001];
	iota(p, p+500001, 0);
	vi v;
	for(int i = q-1; i >= 0; i--) {
		if(t[i] == 1) {
			v.push_back(p[x[i]]);
		} else {
			p[x[i]] = p[y[i]];
		}
	}

	reverse(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}
