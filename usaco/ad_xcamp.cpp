#include <bits/stdc++.h>

using namespace std;

int main() {
	long long N; cin >> N;
	vector<long long> v(N);
	for(long long i = 0; i < N; i++)
		cin >> v[i];

	// smaller to the left
	stack<pair<long long, long long>> s;
	vector<long long> left(N);

	for(long long i = N-1; i >= 0; i--) {
		while(!s.empty() && v[i] < s.top().first) {
			left[s.top().second] = i+1;
			s.pop();
		}
		s.push(make_pair(v[i], i));
	}
	while(!s.empty()) {
		left[s.top().second] = 0;
		s.pop();
	}

	// smaller to the right
	s = stack<pair<long long, long long>>();
	vector<long long> right(N);

	for(long long i = 0; i < N; i++) {
		while(!s.empty() && v[i] < s.top().first) {
			right[s.top().second] = i+1;
			s.pop();
		}
		s.push(make_pair(v[i], i));
	}
	while(!s.empty()) {
		right[s.top().second] = N+1;
		s.pop();
	}

	// final calc
	long long ans = 0;
	for(long long i = 0; i < N; i++) {
		ans = max(ans, (right[i]-left[i]-1)*v[i]);
	}
	cout << ans << endl;

	return 0;
}
