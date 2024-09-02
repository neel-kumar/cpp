#include <bits/stdc++.h>
using namespace std;

int N, M, cereals[100001];
vector<pair<int, int>> cows;

int claim(int ce, int co) {
	int curr = cereals[ce];
	if(curr < co && curr != -1)
		return 0;
	cereals[ce] = co;
	if(curr == -1)
		return 1;

	if(cows[curr].first == ce)
		return claim(cows[curr].second, curr);
	else
		return 0;
}

int main() {
	memset(cereals, -1, sizeof(cereals));
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		int f, s; cin >> f >> s;
		cows.push_back(make_pair(f, s));
	}

	int curr_ans = 0;
	vector<int> ans(N);
	for(int i = N-1; i >= 0; i--) {
		curr_ans += claim(cows[i].first, i);
		ans[i] = curr_ans;
	}
	for(int i = 0; i < N; i++)
		cout << ans[i] << endl;

	return 0;
}
