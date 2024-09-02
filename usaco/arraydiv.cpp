#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

vector<ll> x;
ll n, k;

bool ist(ll m) {
	ll c = 1, rs = 0;
	for(ll i = 0; i < n; i++) {
		rs += x[i];
		if(rs > m) {
			c++;
			rs = x[i];
		}
		if(c > k) return false;
	}
	return true;
}

int main() {
	cin >> n >> k;
	ll l = 0, r = 0;
	for(ll i = 0; i < n; i++) {
		ll xi; cin >> xi; x.push_back(xi);
		l = max(l, xi);
		r += xi;
	}

	while(l <= r) {
		ll m = l + (r-l)/2;
		if(ist(m)) r = m-1;
		else l = m+1;
	}

	cout << l << "\n";

	return 0;
}
