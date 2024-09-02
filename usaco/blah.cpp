#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll findItems(ll arr[], ll n, ll temp) {
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans += (temp/arr[i]);
	return ans;
}

ll bs(ll arr[], ll n, ll m, ll high) {
	ll low = 0;

	while (low < high)
	{
		ll mid = (low+high)>>1;

		ll itm = findItems(arr, n, mid);
        cout << mid << ", " << itm << "\n";

		if (itm < m)
			low = mid+1;

		else
			high = mid;
	}

	return high;
}

ll minTime(ll arr[], ll n, ll m) {
	ll maxval = INT_MIN;

	for (ll i = 0; i < n; i++)
		maxval = max(maxval, arr[i]);

	return bs(arr, n, m, maxval*m);
}

int main() {
	ll n, m, arr[200000];
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
	cout << minTime(arr, n, m) << endl;

	return 0;
}
