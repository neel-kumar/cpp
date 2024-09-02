#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
vector<int> lr(400005);
array<int,3> upd[400005];
array<int,2> qs[400005];
int dif[400005];
int ps[400005];

int gi (int i) { return lower_bound(lr.begin(),lr.end(),i)-lr.begin(); }

// NOTE: REDO THIS IN YOUR WAY

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>q;
	for(int i=0;i<n;i++) {
		int a,b,c; cin>>a>>b>>c;
		upd[i]={a,b,c};
		lr[i*2]=a;
		lr[i*2+1]=b;
	}
	for(int i=0;i<q;i++) {
		int a,b; cin>>a>>b;
		lr.push_back(a);
		lr.push_back(b);
		qs[i]={a,b};
	}

	sort(lr.begin(),lr.end());
	vector<int> lrt;
	int i;
	for(i=0;i<lr.size()-1;i++) {
		int j=i;
		lrt.push_back(lr[i]);
		while(j < lr.size()-1 && lr[i]==lr[j+1]) j++;
		i=j;
	}
	if(i<lr.size()) lrt.push_back(lr[i]);
	lr = lrt;

	/* int dif[n+1]; */
	/* memset(dif,0,sizeof(dif)); */
	/* memset(dif,0,(n+1)*sizeof(int)); */

	/* auto gi = [&](int i) { return lower_bound(lr.begin(),lr.end(),i)-lr.begin(); }; */
	for(int i=0;i<n;i++) {
		dif[gi(upd[i][0])+1] += upd[i][2];
		dif[gi(upd[i][1])+1] -= upd[i][2];
	}

	ps[0]=0;
	int c=0;
	for(int i=1;i<lr.size();i++) {
		c+=dif[i];
		ps[i]=ps[i-1]+c*(lr[i]-lr[i-1]);
	}

	for(int i=0;i<q;i++) cout<<ps[gi(qs[i][1])]-ps[gi(qs[i][0])]<<endl;
}
