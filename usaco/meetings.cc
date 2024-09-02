#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4*5+1;
vector<array<int,3>> wxd;
vector<int> neg, pos;

signed main() {
	#ifndef LJ // g++ -DLJ
	freopen("meetings.in", "r", stdin); freopen("meetings.out", "w", stdout);
	#endif

	int n, l, tar=0;
	cin>>n>>l;
	wxd.resize(n);
	for(int i=0;i<n;i++) {
		cin>>wxd[i][0]>>wxd[i][1]>>wxd[i][2];
		tar+=wxd[i][0];
	}
	sort(wxd.begin(), wxd.end(), [](const array<int,3> &c1, const array<int,3> &c2) {
			return c1[1] < c2[1]; });

	for(int i=0;i<n;i++) {
		if(wxd[i][2]==-1) neg.push_back(i);
		else pos.push_back(i);
	}

	// time
	multiset<pair<int,int>> s;
	for(int i=0;i<neg.size();i++) {
		s.insert({wxd[neg[i]][1], wxd[i][0]});
	}
	for(int i=0;i<pos.size();i++) {
		s.insert({l-wxd[pos[i]][1], wxd[neg.size() + i][0]});
	}

	int t=-1;
	for(const auto &[time, weight] : s) {
		t = time;
		tar -= 2*weight;
		if(tar <= 0) break;
	}
	assert(t!=-1);

	// fin
	int ans=0;
	queue<int> q;
	for(int i=0;i<n;i++) {
		if(wxd[i][2]==1) {
			q.push(wxd[i][1]);
		} else {
			int nx = wxd[i][1]-2*t;
			while(!q.empty() && q.front() < nx) q.pop();
			ans+=q.size();
		}
	}
	cout<<ans<<endl;
}
