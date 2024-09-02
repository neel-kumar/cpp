#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,m; cin >> n >> m;
	vector<array<int,3>> fl[n]; // arrival time, destination, fin time
	int a[n];
	queue<pi> q; // arrival node, time of dest
	for(int i = 0; i < m; i++) {
		int x; cin>>x;
		x--;
		int y1,y2,y3;
		cin>>y1>>y2>>y3;
		y2--;
		fl[x].push_back({y1,y2,y3});
	}
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sort(fl[i].begin(), fl[i].end()); // popback when processing new flights
		if(i==0) {
			for(int i = fl[0].size()-1; i>=0; i--) q.push({fl[0][i][1], fl[0][i][2]});
			a[0]=0;
		}
	}

	// process queue
	int ans[n]; for(int i=1;i<n;i++) ans[i]=INT_MAX;
	ans[0]=0;

	while(!q.empty()) {
		pi p = q.front(); q.pop();
		ans[p.f]=min(ans[p.f],p.s);
		/* print(fl[p.f]); */
		while(fl[p.f].size() && fl[p.f].back()[0] >= p.s+a[p.f]) {
			q.push({fl[p.f].back()[1], fl[p.f].back()[2]});
			fl[p.f].pop_back();
		}
	}

	for(int i=0;i<n;i++) cout << (ans[i]==INT_MAX?-1:ans[i]) << endl;
}
