#include <bits/stdc++.h>

using namespace std;


int N, ans[200001];
map<int, vector<int>> tree;
int traversal(int node) {
	for(int i : tree[node]) {
		ans[node] += traversal(i);
	}
	return ans[node]+1;
}

int main() {
	cin >> N;
	for(int i = 1; i < N; i++) {
		int x; cin >> x;
		tree[x-1].push_back(i);
	}

	traversal(0);
	for(int i = 0; i < N; i++)
		cout << ans[i] << " ";
	return 0;
}
