/*
 * 1
 * 2 3 4
 * 5 6 7 8 9
 * 10 11 12 13 14 15 16
 * 17 18 19 20 21 22 23 24 25
 * 26 27 28 29 30 31 32 33 34 35 36
 * input format: (y, x)
 *
 * OBS(ring index = ri):
 * ri of a given input: max(y, x)
 * first # of ring: (last # of ri-1) + 1
 * middle # of ring: (ri^2)-(ri-1)
 * last # of ring: ri^2
 *
 * SudoCode:
 * if(x == y) middle(x);
 * else if(y == 1)
 *      if(x == even) first(x);
 *      else last(x);
 * else if(x == 1)
 *      if(y == even) last(x);
 *      else first(x);
 * else
 *
 * CODE???:
 * if y is max:
 *      if(y == even) last(y)-x
 *      else first(y)+x
 * else:
 *      if(x == even) first(x)+y
 *      else last(x)-y
 */

#include <iostream>

using namespace std;
#define ll long long

ll n;

int main() {
	cin >> n;
	for(ll i = 0; i < n; i++) {
		ll y, x;
		cin >> x >> y;
		if(x >= y) {
			if(x%2 == 0) cout << ((x*x)-y+1) << "\n";
			else cout << (((x-1)*(x-1))+y) << "\n";
		} else {
			if(y%2 == 0) cout << (((y-1)*(y-1))+x) << "\n";
			else cout << ((y*y)+1-x) << "\n";
		}
	}
	return 0;
}
