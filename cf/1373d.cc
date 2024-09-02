#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(vector<int> a) {
	assert(a.size()%2==0);
	int mx=0,j=0,c=0;
	for(int i=0;i<a.size();i+=2) {
		while(j<a.size() && c>=0) {
			if(j%2==0) c+=a[j+1]-a[j];
			else c+=a[j]-a[j+1];
			mx=max(mx,c);
			j+=2;
		}
	}

	j=1,c=0;
	for(int i=1;i<a.size();i+=2) {
		while(j<a.size()-1 && c>=0) {
			if(j%2==0) c+=a[j+1]-a[j];
			else c+=a[j]-a[j+1];
			mx=max(mx,c);
			j+=2;
		}
	}
	return mx;
}

int gs(vector<int> a) {
	// greatest substring
	set<int> ps;
	int c=0,mx=0;
	for(int i : a) {
		ps.insert(c);
		c+=i;
		mx=max(mx,c-*ps.begin());
	}
	return mx;
}
void solve() {
	int n,sum=0; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(i%2==0) sum+=a[i];
	}

	vector<int> a1;
	for(int i=0;(i+1)<n;i+=2) a1.push_back(a[i+1]-a[i]);
	vector<int> a2;
	for(int i=1;(i+1)<n;i+=2) a2.push_back(a[i]-a[i+1]);

	/* for(int i : a1) cout << i << ' '; cout << endl; */
	/* for(int i : a2) cout << i << ' '; cout << endl; */
	/* printf("%lld %lld %lld\n",sum,gs(a1),gs(a2)); */

	cout << sum+max(gs(a1),gs(a2)) << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
