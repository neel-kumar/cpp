#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1.5 * 1e5;
long long N, Q;
long long highest; // orginal highest
long long def[MAXN+1]; // original: milk/min
vector<long long> milk_values; // for binary search
vector<long long> ps; // for the -/+ in final operation

long long last_true(long long lo, long long hi, long long val) {
	lo--;
	for (long long dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && milk_values[lo + dif] <= val) { lo += dif; }
	}
	return lo;
}

int main() {
	cin >> N;
	milk_values.push_back(-1);
	for(long long i = 0; i < N; i++) {
		cin >> def[i+1];
		milk_values.push_back(def[i+1]);
	}

	// constructing the prefix sum and highest
	sort(milk_values.begin(), milk_values.end());
	long long pscurr = 0;
	ps.push_back(0);
	for(long long i = 1; i <= N; i++) {
		pscurr += milk_values[i];
		highest += milk_values[i]*i;
		ps.push_back(pscurr);
	}

	cin >> Q;
	while(Q--) {
		long long cow, change; cin >> cow >> change;
		long long s = last_true(0, N, def[cow]), f = last_true(0, N, change);
		f++;
		f -= (f > s);
		long long ans = highest - (s*def[cow]) + (f*change);
		if(f == s) {
			cout << ans << endl;
			continue;
		}
		if(f > s) {
			ans -= ps[f]-ps[s];
		} else {
			ans += ps[s-1] - ps[f-1];
		}
		cout << ans << endl;
	}
	return 0;
}
