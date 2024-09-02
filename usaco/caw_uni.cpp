#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n), b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	ll ans = INT_MAX;
	multiset<ll> sb;
	ll l = 0;
	ll sum = 0;
	for(int r = 0; r < n; r++) {
		sb.insert(b[r]);
		sum += a[r];
		while(sum-a[l] >= m) {
			sum -= a[l];
			sb.erase(sb.find(b[l]));
			l++;
		}
		if(sum >= m) ans = min(ans, *sb.rbegin());
	}

	cout << ans << endl;

	return 0;
}

