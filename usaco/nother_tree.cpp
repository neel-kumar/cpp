#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> t[501];
set<int> ans[501][501];
int dans[501][501];

void dfs(int r, int n, int p, set<int> bs) {
	set<int> nb = bs;
	nb.insert(n);

	for(int c : t[n]) {
		if(c==p) continue;
		dfs(r, c, n, nb);
	}

	vector<int> rem;
	for(int i : ans[r][n]) {
		if(nb.count(i) == 0) rem.push_back(i);
	}
	for(int i : rem) {
		ans[r][n].erase(ans[r][n].find(i));
	}
}

long long countSetBits(long long n) {
    long long count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void dd(int r, int n, int p, int pa) {
	dans[r][n] = pa+1;
	for(int c : t[n]) {
		if(c==p) continue;
		dd(r, c, n, pa+1);
	}
}

void ds() {
	for(int i=1; i < n; i++) {
		int a, b; cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}

	for(int i=1; i <= n; i++) {
		dd(i, i, -1, 0);
	}

	for(int i=1; i <= n; i++) {
		for(int j=1; j <= n; j++) {
			cout << dans[i][j] << ' ';
		}
		cout << '\n';
	}
}

void start() {
	int pmid = -1;
	bool works = 1;
	for(int i = 0; i < k; i++) {
		map<int,int> o;
		int mid=-1;
		for(int i =1; i < n; i++) {
			int a, b; cin >> a >> b;
			o[a]++;
			o[b]++;
			if(o[a] > 1) mid=a;
			else if(o[b] > 1) mid=b;
		}
		if(mid != pmid && pmid != -1) works = false;
		pmid = mid;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) cout << "1 ";
			else cout << (2+ (i!=pmid && j!=pmid && works)) << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin >> n >> k;
	if(k == 1) {
		ds();
		return 0;
	}

	set<int> s;
	for(int i = 1; i <= n; i++) s.insert(i);
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			ans[i][j] = s;
		}
	}

	for(int j=0; j<k; j++) {
		for(int i=1; i <= n; i++) t[i].clear();
		for(int i=1; i < n; i++) {
			int a, b; cin >> a >> b;
			t[a].push_back(b);
			t[b].push_back(a);
		}
		for(int i=1; i <= n; i++) {
				dfs(i, i, -1, {});
		}
	}

	for(int i=1; i <= n; i++) {
		for(int j=1; j <= n; j++) {
			cout << ans[i][j].size() << ' ';
		}
		cout << '\n';
	}
}
