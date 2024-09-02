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

void solve(){
	int n; cin>>n;
	string s1,s2; cin>>s1>>s2;
	int c1=0,c2=0,dif=0;
	for(int i=0;i<n;i++) {
		dif+=(s1[i]!=s2[i]);
		c1+=(s1[i]=='1');
		c2+=(s2[i]=='1');
	}
	cout << abs(c1-c2)+(dif-abs(c1-c2))/2 << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}
