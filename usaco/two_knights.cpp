#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	// calculate all placements - knights attack
	for(ll i = 1; i <= n; i++) {
		ll all_place = (i*i) * (i*i -1)/2;
		ll knights = (i-1)*(i-2)*4;
		cout << all_place-knights << endl;
	}

	return 0;
}
