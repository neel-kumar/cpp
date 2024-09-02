#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	vector<pair<int, int>> v(N);
	for(int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());

	stack<int> s;
	s.push(v[0].second);
	for(int i = 1; i < N; i++) {
		int temp = v[i].second;
		while(!s.empty() && s.top() <= v[i].second) {
			temp = min(s.top(), temp);
			s.pop();
		}
		s.push(temp);
	}

	cout << s.size() << endl;
	return 0;
}
