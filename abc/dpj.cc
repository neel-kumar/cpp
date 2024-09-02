#include <bits/stdc++.h>
using namespace std;

const int MX = 600;
int n;
long double memo[MX][MX][MX];

long double dp(int a, int b, int c) {
	if(a==0 && b==0 && c==0) return 0;
	if(a<0 || b<0 || c<0) return 0;
	if(memo[a][b][c] > 0) return memo[a][b][c];

	return memo[a][b][c] = (n + dp(a-1,b,c)*a + dp(a+1,b-1,c)*b + dp(a,b+1,c-1)*c) / (a+b+c);
}

signed main() {
	cin >> n;
	int a=0,b=0,c=0;
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		a += (x==1);
		b += (x==2);
		c += (x==3);
	}

	cout << setprecision(10) << dp(a,b,c) << endl;
}
