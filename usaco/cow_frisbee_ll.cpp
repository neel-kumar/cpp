#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	int a[n], oa[n];
	vector<int> prev(n), next(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		oa[a[i]] = i;
		prev[i] = i-1;
		next[i] = i+1;
	}
	sort(a, a+n);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int cur_i = oa[a[i]];
		if(prev[cur_i] != -1)
			ans += cur_i - prev[cur_i]+1, next[prev[cur_i]] = next[cur_i];
		if(next[cur_i] != n)
			ans += next[cur_i] - cur_i+1, prev[next[cur_i]] = prev[cur_i];
	}
	cout << ans << endl;

	return 0;
}
