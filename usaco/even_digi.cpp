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

string base_repr(long long N, int base) {
	if(N==0)return "0";
	string res="";
	while(N>0) {
		res+=char('0'+N%base);
		N/=base;
	}
	reverse(res.begin(), res.end());
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	string s=base_repr(n-1,5);
	char dm[5]={'0','2','4','6','8'};
	for(int i=0;i<s.size();i++)
		s[i]=dm[s[i]-'0'];
	cout << s << endl;
}
