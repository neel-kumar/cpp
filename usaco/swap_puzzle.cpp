#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

int n,m;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> a(n ,vector<int>(m)), b(n, vector<int>(m));

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> b[i][j];

	queue<pair<int, vector<vector<int>>>> q;
	q.push({0,a});
	set<vector<vector<int>>> vis;
	int cnt=0;
	while(!q.empty()) {
		auto curr = q.front(); q.pop();
		if(vis.count(curr.s)) continue;
		vis.insert(curr.s);
		if(curr.s == b) {
			cout << curr.f << endl;
			return 0;
		}

		for(int i = 0; i < n-1; i++) {
			auto sr = curr.s;
			swap(sr[i], sr[i+1]);
			if(vis.count(sr) == 0) {
				q.push({curr.f+1, sr});
			}
		}

		for(int i = 0; i < m-1; i++) {
			auto sr = curr.s;
			for(int k = 0; k < n; k++) {
				swap(sr[k][i], sr[k][i+1]);
			}
			if(vis.count(sr) == 0) {
				q.push({curr.f+1, sr});
			}
		}
	}

	cout << "-1\n";
}
