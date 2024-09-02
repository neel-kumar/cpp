#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a, b, c;
	vector<pair<int, int>> arr;
	for(int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		arr.push_back({b+c, a});
	}
	sort(arr.begin(), arr.end(), greater<pair<int, int>>());
	int curr = 0, ans = 0;
	for(auto i : arr) {
		curr += i.second;
		ans = max(ans, curr+i.first);
	}
	cout << ans << endl;
	return 0;
}
