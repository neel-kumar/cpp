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

const double eps = 1e-7;

int n;
vector<double> x,y;

bool check(double t) {
	double l=0,r=1e9;
	for(int i=0;i<n;i++) {
		l=max(l,x[i]-t*y[i]);
		r=min(r,x[i]+t*y[i]);
	}
	return l<=r;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	cin>>n;
	x.resize(n);
	y.resize(n);
	for(int i=0;i<n;i++)
		cin>>x[i];
	for(int i=0;i<n;i++)
		cin>>y[i];

	double l=0,r=1e9;
	while(r-l > eps) {
		double mid=(l+r)/2.0;
		/* printf("l: %.10f, r: %.10f, mid: %.10f\n",l,r,mid); */
		if(check(mid))
			r=mid;
		else
			l=mid;
	}

	cout<<fixed<<setprecision(10)<<l<<'\n';
}
