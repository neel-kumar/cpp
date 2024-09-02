#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int a[3]; for(int i=0;i<3;i++) cin>>a[i];
	sort(a,a+3);
	if(a[2]>=(a[1]*2+a[0]*2))
		a[2]=a[1]*2LL+a[0]*2;
	cout << (a[0]+a[1]+a[2])/3LL << endl;
}
