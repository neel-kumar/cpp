#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	scanf("%lld %lld", &n, &k);
	ld ans=0;
	for(int i=1;i<=k;i++) {
		ld add=1,sub=1;
		for(int j=1;j<=n;j++) {
			add*=(ld)i/(ld)k;
			sub*=(ld)(i-1)/(ld)k;
		}
		ans+=(ld)(i)*(ld)(add-sub);
	}
	printf("%.6Lf", ans);
}
