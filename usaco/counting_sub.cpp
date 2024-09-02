#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> tree;
int memo[200001];
int emp[200001];

int dp(int node) {
	for(int sub : tree[node]) {
		emp[node] += dp(sub);
	}
	return emp[node]+1;
}

int main() {
	int N; cin >> N;
	for(int i = 0; i < N-1; i++) {
		int x; cin >> x;
		tree[x].push_back(i+2);
	}
	dp(1);
	for(int i = 1; i <= N; i++) cout << emp[i] << " ";
	return 0;
}
