#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int c[7]; memset(c,0,sizeof(c));
	string s; cin>>s;
	int ans=0, left=s.length();

	for(char i : s) {
		c[0]++;
		switch(i) {
			case 'b':
				c[1]+=c[0]; c[0]=0;
				break;
			case 'e':
				c[2]+=c[1]; c[1]=0;
				c[6]+=c[5]; c[5]=0;
				break;
			case 's':
				c[4]+=c[3]; c[3]=0;
				c[3]+=c[2]; c[2]=0;
				break;
			case 'i':
				c[5]+=c[4]; c[4]=0;
				break;
		}
		ans += c[6]*left;
		c[0]+=c[6];
		c[6]=0;
		left--;
	}

	printf("%lld\n",ans);
}
