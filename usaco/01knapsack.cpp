#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

// int n, x, memo[100001][1001];
int n, x, memo[1001][100001];
int p[1001], g[1001];

int main() {
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> g[i];
	}

	for(int pi = 1; pi <= x; pi++) {
		for(int ni = 1; ni <= n; ni++) {
			//if((pi - p[ni]) < 0) memo[pi][ni] = memo[pi][ni-1];
			//else memo[pi][ni] = max(memo[pi][ni-1], g[ni]+memo[pi-p[ni]][ni-1]);

			// if((pi - p[ni]) >= 0) memo[pi][ni] = max(memo[pi][ni-1], g[ni]+memo[pi-p[ni]][ni-1]);
			// else memo[pi][ni] = memo[pi][ni-1];

			int tmp = memo[ni-1][pi];
			if(pi >= p[ni]) tmp = max(tmp, g[ni]+memo[ni-1][pi-p[ni]]);
			memo[ni][pi] = tmp;


			//            cout << memo[pi][ni] << " ";
		}
		//        cout << "\n";
	}

/* 	cout << memo[n][x] << "\n"; */

	return 0;
}
