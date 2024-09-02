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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	int a[n], f[n], b[n];
	for(int i=0;i<n;i++) cin >> a[i];

	f[0]=(a[0]>0?1:0);
	for(int i=1;i<n;i++) {
		if(a[i]>f[i-1]) f[i]=f[i-1]+1;
		else {
			f[i]=a[i];
		}
	}

	b[n-1]=(a[n-1]>0?1:0);
	for(int i=n-2;i>=0;i--) {
		if(a[i]>b[i+1]) b[i]=b[i+1]+1;
		else {
			b[i]=a[i];
		}
	}

	int ans=0;
	for(int i=0;i<n;i++) ans=max(ans, min(f[i],b[i]));
	cout << ans << endl;
}
