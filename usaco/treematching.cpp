// recursively w/ breaking down subtrees: di(r) = sigma over all children c max(di(c), dni(c))
// dni(r) = di(r) + max over all children c(-max(di(c), dni(c)) + di(c) + 1) 

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree[200001];
pair<int, int> memo[200001];

// first include, second don't include
pair<int, int> solve(int r, int prev) {
	if(tree[r].size() == 1 && r != 1) return make_pair(0, 0);
	else {
		int dni = 0;
		for(int i : tree[r]) {
			if(i == prev) continue;
			memo[i] = solve(i, r);
			dni += max(memo[i].first, memo[i].second);
		}
		int di = dni;
		int m = INT32_MIN;
		for(int i : tree[r]) {
			if(i == prev) continue;
			m = max(memo[i].second+1-max(memo[i].first, memo[i].second), m);
		}
		di += m;
		return make_pair(di, dni);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int x, y; cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	cout << max(solve(1, -1).first, solve(1, -1).second);
	return 0;
}
