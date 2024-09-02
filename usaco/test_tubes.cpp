/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef bitset<1000000001> bs;
/*
 * bs[i]        =>  set.count(i)
 * bs.set(i)    =>  set.insert(i)
 * bs.reset(i)  =>  set.erase(i)
 * bs.count()   =>  set.size()
 *
 * priority_queue <int, vector<int>, greater<int> > pq; minheap
 */
using ld = long double;
using ll = long long;
#define f first
#define s second

int n,p;

vector<pi> f(string s1, string s2) {
	int i=0;
	for(;i<n;i++) if(s1[i]=='2') break;
	if(i==n) s1="";
	else s1=s1.substr(i,n);

	for(i=0;i<n;i++) if(s2[i]=='1') break;
	if(i==n) s2="";
	else s2=s2.substr(i,n);

	string ns1="",ns2="";
	char prev=' ';
	for(char c : s1) {
		if(c!=prev) ns1+=c;
		prev=c;
	}
	prev=' ';
	for(char c : s2) {
		if(c!=prev) ns2+=c;
		prev=c;
	}
	s1=ns1;s2=ns2;

	vector<pi> ans;
	if(s2.size() && s2[s2.size()-1]=='2') {
		ans.push_back({2,3});
		s2=s2.substr(0,s2.size()-1);
	}
	for(i=s1.size()-1;i>=0;i--) {
		if(s1[i]=='1') ans.push_back({1,2});
		else if(s1[i]=='2' && !s2.size()) ans.push_back({1,2});
		else ans.push_back({1,3});
	}
	for(i=s2.size()-1;i>=0;i--) {
		if(s2[i]=='2') ans.push_back({2,3});
		else if(s2[i]=='1' && !s1.size()) ans.push_back({2,1});
		else ans.push_back({2,1});
	}
	if(min(s1.size(),s2.size()) > 0) ans.push_back({3,2});
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t;cin>>t;
	while(t--) {
		cin>>n>>p;
		string s1,s2; cin>>s1>>s2;

		vector<pi> ans1 = f(s1,s2);
		vector<pi> ans2 = f(s2,s1);
		if(ans2.size() < ans1.size()) {
			vector<pi> ans=ans2;
			cout << ans.size() << endl;
			if(p>1) {
				for(pi ansi : ans) {
					int x=ansi.f;
					if(x==1) x=2;
					else if(x==2) x=1;
					int y=ansi.s;
					if(y==1) y=2;
					else if(y==2) y=1;
					cout << x << ' ' << y << endl;
				}
			}
		} else {
			vector<pi> ans=ans1;
			cout << ans.size() << endl;
			if(p>1) {
				for(pi ansi : ans) cout << ansi.f << ' ' << ansi.s << endl;
			}
		}
	}
}
