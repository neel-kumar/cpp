#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6+3;
long long works[maxn];

signed main() {
	long long a, b, c, d; cin >> a >> b >> c >> d;
	for(long long i = a; i <= b; i++) {
		works[i+b]++;
		works[i+c+1]--;
	}
	for(long long i = 1; i < maxn; i++) works[i] += works[i-1];
	for(long long i = 1; i < maxn; i++) works[i] += works[i-1];
	long long ans = 0;
	for(long long i = c; i <= d; i++) ans += works[maxn-1] - works[i];
	cout << ans << endl;

	return 0;
}
