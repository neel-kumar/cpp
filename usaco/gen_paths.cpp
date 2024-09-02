#include <bits/stdc++.h>
using namespace std;

int n;//nodes
vector<int> t[501];
long long ans[501][501];

void dfs(int r, int n, int p, long long bs) {
	int nb = bs|(1<<n-1);

	for(int c : t[n]) {
		if(c==p) continue;
		dfs(r, c, n, nb);
	}

	ans[r][n] = nb;
}

long long countSetBits(long long n) {
    long long count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
	cin >> n;
	for(int i=1; i < n; i++) {
		int a, b; cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}

	for(int i=1; i <= n; i++) {
		dfs(i, i, -1, 0);
	}

	for(int i=1; i <= n; i++) {
		for(int j=1; j <= n; j++) {
			cout << countSetBits(ans[i][j]) << ' ';
		}
		cout << '\n';
	}
}
