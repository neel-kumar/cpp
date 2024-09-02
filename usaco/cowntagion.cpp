#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100005];

int dfs(int r, int p) {
	int ret = 0;
	int cnt = 0;
	for(int c : g[r]) {
		if(c == p) continue;
		ret += 1+dfs(c, r);
		cnt++;
	}
	while(cnt > 0) {
		ret++;
		cnt /= 2;
	}
	return ret;
}


int main() {
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cout << dfs(1, -1);
}
