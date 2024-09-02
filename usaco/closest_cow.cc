#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int k,m,n; cin>>k>>m>>n;
	vector<int> c;
	vector<pair<int,int>> p;
	for(int i=0;i<k;i++) {
		int x,y; cin>>x>>y;
		p.push_back({x,y});
	}
	for(int i=0;i<m;i++) {
		int x; cin>>x;
		p.push_back({x,-1});
	}
	sort(p.begin(),p.end());

	vector<int> fin;
	int i=(p[0].second==-1)?1:0;
	while(i<p.size()) {
		int x=0, j=i;
		while(i<p.size() && p[i].second!=-1) {
			x+=p[i].second;
			i++;
		}

		// (j,i]
		if(j > 0 && p[j-1].second == -1 && i != p.size() && p[i].second == -1) {
			assert(p[j-1].second == -1 && p[i].second == -1);
			int l=j, r=j, mx=0, cur=0, lim0=p[j-1].first, lim1=p[i].first;
			for(; l < i; l++) {
				/* while(r < i && lim1-p[r].first+p[l].first-lim0 > p[r].first-p[l].first) { */
				while(r < i && 2*(p[r].first-p[l].first) < lim1-lim0) {
					cur+=p[r].second;
					r++;
				}
				mx=max(cur,mx);
				cur-=p[l].second;
			}
			assert(mx*2 >= x);
			fin.push_back(mx);
			fin.push_back(x-mx);
		} else {
			fin.push_back(x);
		}
		while(i<p.size() && p[i].second==-1) i++;
	}

	sort(fin.rbegin(),fin.rend());
	int ans=0;
	for(int i=0;i<n;i++) ans+=fin[i];
	cout << ans << endl;
}
