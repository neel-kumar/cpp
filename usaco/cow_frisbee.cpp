#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	long long ans = 0;
	vector<int> s;
	for(int i = 0; i < n; i++) {
		while(!s.empty() && a[s.back()] <= a[i]) {
			ans += i-s.back()+1;
			s.pop_back();
		}
		if(!s.empty()) {
			ans += i-s.back()+1;
		}
		s.push_back(i);
	}
	cout << ans << endl;
}
cout << ans << endl;
}
