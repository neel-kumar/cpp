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
    ((cout << args << " "), ...);
    cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,q; cin >> n >> q;
	vi x(n), y(n);
	for(int i=0; i<n; i++) {
		x[n-i-1]=0;
		y[n-i-1]=i+1;
	}

	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			char d; cin >> d;
			int xc=0, yc=0;
			if(d == 'L') yc=-1;
			else if(d == 'R') yc=1;
			else if(d == 'U') xc=1;
			else xc=-1;
			x.push_back(x.back()+xc);
			y.push_back(y.back()+yc);
		} else {
			int p; cin >> p;
			print(y[y.size()-p], x[x.size()-p]);
		}
	}
}
