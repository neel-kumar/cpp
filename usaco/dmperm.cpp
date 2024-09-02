#include <bits/stdc++.h>
using namespace std;

signed main() {
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	do {
		int d = arr[0], h = arr[1], n = arr[2], t = arr[3], a = arr[4], i = arr[5], r = arr[6], l = arr[7], w = arr[8];
		if( l+w < 10 ) continue;
		if( (l+w)%10 != a ) continue;
		if(d+d != h) continue;
		if(n+n != t) continue;
		int ans = h + 10*t + 100*r + 1000*(l+w);
		cout << ans << endl;
	} while ( next_permutation(arr,arr+10) );
}
