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

	int n; cin >> n;

	int a=0,b=0,c=0;
	int clim=n, blim=n;

	while(a != n) {
		print(a,b,c);
		/* cerr << "LIMS: " << blim << " " << clim << endl; */

		if(c < clim) c++;
		else {
			clim--;
			c=0;
			b++;
		}

		if(b > blim) {
			a++;
			b=0;
			c=0;
			blim = n-a;
			clim = n-a;
		}
	}
	print(a,b,c);
}
