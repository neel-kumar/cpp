/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second

int f(string s, int k) {
	int ans=INT_MAX, ch=0, l=0, r=0;
	bool works=0;
	while(r<(int)s.size()) {
		while(r-l < k && r<(int)s.size()) {
			ch+=s[r]=='.';
			if(s[r]=='x') {
				ch=0;
				l=r+1;
			}
			r++;
			/* printf("R %lld %lld %lld\n", l, r, ch); */
		}

		/* printf("WHILE %lld %lld %lld\n", l, r, ch); */
		if(r-l>=k) {
			works=1;
			ans=min(ans,ch);
		}
		l++;
		ch-=s[l-1]=='.';
	}
	if(!works) return -1;
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int h,w,k; cin>>h>>w>>k;
	string ver[h],hor[w];
	for(int i=0;i<h;i++) ver[i]="";
	for(int i=0;i<w;i++) hor[i]="";

	for(int i=0;i<h;i++) {
		string s; cin>>s;
		ver[i]=s;
		for(int j=0;j<w;j++)
			hor[j]+=s[j];
	 }

	int ans=INT_MAX;
	bool works=0;
	for(int i=0;i<h;i++) {
		int ret=f(ver[i],k);
		if(ret!=-1) {
			works=1;
			ans=min(ans,ret);
		}
	}
	for(int i=0;i<w;i++) {
		int ret=f(hor[i],k);
		if(ret!=-1) {
			works=1;
			ans=min(ans,ret);
		}
	}
	if(!works) cout<<-1<<endl;
	else cout<<ans<<endl;
}
