#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

const int M=1e9+7;

signed main() {
	int n; cin >> n;
	vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=n-1;i>1;i--) {
		vector<int> b;
		pair<int,int> cur={0,1},nxt={1,2};
		for(int j=0;j<i;j++) {
			if(nxt.s>i) {
				b.push_back(a[cur.f]+a[cur.s]);
				cur.s++;
				if(cur.s>=i) cur={cur.f+1,cur.f+2};
				continue;
			}
			if(a[cur.f]+a[cur.s] > a[nxt.f]+a[nxt.s]) {
				b.push_back(a[nxt.f]+a[nxt.s]);
				nxt.s++;
				if(nxt.s>i) nxt={nxt.f+1,nxt.f+2};
			} else {
				b.push_back(a[cur.f]+a[cur.s]);
				cur.s++;
				if(cur.s>i) {
					cur={nxt.f,nxt.s};
					nxt={cur.f+1,cur.f+2};
				}
			}
		}

		int rem = b[0]-b[0]%M;
		for(int& j:b) j-=rem;
		a=b;
	}
	cout << (a[0]+a[1])%M << endl;
}
