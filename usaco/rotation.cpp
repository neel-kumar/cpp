#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,q;
	string s;
	cin >> n >> q >> s;

	int c=0;
	while(q--) {
		int x,y; cin >> x >> y;
		if(x==1) c+=y;
		else {
			cout << s[(y-1-c+n)%n] << endl;
		}
		c%=n;
	}
}
