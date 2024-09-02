#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll X[2000005],Y[2000005];
ll n;
ll S;

// Find all possible sum of elements of a[] and store
// in x[]
ll calcsubarray(ll a[], ll x[], ll n, ll c)
{
	ll size = 0;
    for (ll i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (ll j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        if(s <= S) {
			x[size] = s;
			size++;
		}
    }
	return size;
}

// Returns the maximum possible sum less or equal to S
ll solveSubsetSum(ll a[], ll n, ll S)
{
    // Compute all subset sums of first and second
    // halves
    ll size_X = calcsubarray(a, X, n/2, 0);
    ll size_Y = calcsubarray(a, Y, n-n/2, n/2);
	sort(Y, Y+size_Y);

	/*
	sort(Y, Y+size_Y);
	for(int i = 0; i < size_X; i++) cout << X[i] << " ";
	cout << endl;
	for(int i = 0; i < size_Y; i++) cout << Y[i] << " ";
	cout << endl;
	*/

	ll ans = 0;
	// bs to find possible ss in Y to pair w X
	for(ll i = 0; i < size_X; i++) {
		ll val = X[i];
		if(val > S) return ans;

		ll l = 0, r = size_Y-1;
		while(l < r) {
			ll mid = (l+r+1)/2;
			if(Y[mid]+val <= S) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		ans += (l+1);
	}
	return ans;
}

// Driver code
signed main() {
	cin >> n >> S;
    ll a[n];
	for(ll i = 0; i < n; i++) cin >> a[i];
	cout << solveSubsetSum(a,n,S) << endl;
    return 0;
}
