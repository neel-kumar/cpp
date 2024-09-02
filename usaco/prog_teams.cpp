#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			arr[i] = x;
		}
		int ans = 0;
		for(int s = 2; s <= n*2; s++) {
			bool taken[n] = {false};
			int cnt = 0;
			for(int i = 0; i < n; i++) {
				if(taken[i]) continue;
				for(int j = i+1; j < n; j++) {
					if(arr[i]+arr[j] == s && !taken[j]) {
						taken[j] = true;
						taken[i] = true;
						cnt++;
						//cout << t << " " << i << " " << j << endl;
						break;
					}
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;

	}
	return 0;
}

