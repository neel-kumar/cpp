#include <bits/stdc++.h>

using namespace std;

map<int, vector<vector<int>>> tree;
vector<int> prefix;
map<int, int> ans;

void dfs(int n, int sum) {
	//printf("DFS(%d, %d) ", n, sum);
	int lo = 0, hi = prefix.size() -1;
	lo--;
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && prefix[lo+dif] <= sum) { lo += dif; }
	}
	//return lo;
	//lo = upper_bound(prefix.begin(),prefix.end(),sum)-prefix.begin();
	if(prefix[lo] <= sum)
		ans[n] = lo;
	else
		ans[n] = 0;
	for(auto in : tree[n]) {
		prefix.push_back(prefix.back()+in[2]);
		dfs(in[0], sum + in[1]);
		prefix.pop_back();
	}
}

int main() {
	int T; cin >> T;
	while(T--) {
		int N; cin >> N;
		for(int i = 0; i < N-1; i++) {
			int anc;
			vector<int> in(3); cin >> anc >> in[1] >> in[2];
			in[0] = i+2;
			tree[anc].push_back(in);
		}
		prefix.push_back(0);
		dfs(1, 0);
		for(int i = 2; i <= N; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		tree.clear();
		prefix.clear();
		ans.clear();
	}
	return 0;
}
