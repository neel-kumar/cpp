#include <bits/stdc++.h>

using namespace std;

int main() {
	// 1st smaller to the left
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i < N; i++)
		cin >> v[i];
	stack<pair<int, int>> s;
	vector<int> ans(N);

	for(int i = N-1; i >= 0; i--) {
		while(!s.empty() && v[i] < s.top().first) {
			ans[s.top().second] = i+1;
			s.pop();
		}
		s.push(make_pair(v[i], i));
	}
	while(!s.empty()) {
		ans[s.top().second] = 0;
		s.pop();
	}

	for(int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}
