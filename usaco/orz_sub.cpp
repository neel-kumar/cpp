#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int arr[n];
		int ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			ans += (arr[i] <= 0);
		}
		int pos = INT_MAX;
		for(int i = 0; i < n; i++) if(arr[i] > 0) pos = min(pos, arr[i]);
		bool inl_pos = (pos != INT_MAX);
		sort(arr, arr+n);
		for(int i = 1; i < n; i++) {
			if(arr[i] <= 0) inl_pos &= (arr[i] - arr[i - 1] >= pos);
		}
		cout << ans + inl_pos << endl;
	}
	return 0;
}
