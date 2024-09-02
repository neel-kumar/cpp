#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

signed main() {
	int n,p; cin>>n>>p;
	vector<pair<int,int>> posts;
	map<int,multiset<int>> px,py;
	map<pair<int,int>,array<pair<int,int>,4>> close;
	for(int i=0;i<p;i++) {
		int x,y; cin>>x>>y;
		posts.push_back({x,y});
		px[x].insert(y);
		py[y].insert(x);
	}

	for(int i=0;i<p;i++) {
		pair<int,int> ip = posts[i];
		auto itx = px[ip.first].find(ip.second);
		auto ity = py[ip.second].find(ip.first);

		if(itx!=px[ip.first].begin()) {
			close[ip][0]= {ip.first, *(--itx)};
			itx++;
		} else close[ip][0]={-1,-1};
		if(itx!=(--px[ip.first].end())) close[ip][1]={ip.first, *(++itx)};
		else close[ip][1]={-1,-1};

		if(ity!=py[ip.second].begin()) {
			close[ip][2]={*(--ity), ip.second};
			ity++;
		} else close[ip][2]={-1,-1};
		if(ity!=(--py[ip.second].end())) close[ip][3]={*(++ity), ip.second};
		else close[ip][3]={-1,-1};

		cout << "CLOSE " << ip.first << ' ' << ip.second << endl;
		for(pair<int,int> j : close[ip])
			cout <<  "B: " <<j.first << ' ' << j.second << endl;
		cout << endl;
	}

	pair<int,int> beg;
	for(auto i : posts) {
		int x=0;
		for(int j=0;j<4;j++) x+=close[i][j].first!=-1;
		if(x<=2) {
			beg = i;
			break;
		}
	}

	set<pair<int,int>> vis;
	deque<pair<pair<int,int>,int>> q; // post, last direction
	map<pair<int,int>, pair<int,int>> order;

	q.push_back(pair<pair<int, int>,int>{beg,-1});
	vis.insert({beg,-1});

	while(q.size() && vis.size()<p) {
		auto cthing=q.front(); q.pop_front(); pair<int,int> cn=cthing.first; int cd=cthing.second;

		int start=(cd<2?2:0),end=(cd<2?4:2);
		for(int i=start;i<end;i++) {
			pair<int,int> pp = close[cn][i];
			if(vis.count(pp)) {
				close[cn][i]={-1,-1};
				continue;
			}
			for(int i=0;i<4;i++) {
			}
		}
	}

	pair<int,int> curr=beg;
	for(int i=0;i<p-1;i++) {
		cout << curr.first << ' ' << curr.second << endl;
		if(order.count(curr) ==0) {
			cout << "NO\n";
			return 0;
		}
		curr=order[curr];
	}
	cout << curr.first << ' ' << curr.second << endl;
}
