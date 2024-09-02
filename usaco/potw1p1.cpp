#include <bits/stdc++.h>
using namespace std;

int main() {
	int d, h, n, t, a, i, r, l, w;
	// h = d+d
	// t = n+n+tensof(h)
	// r = a+i + tensof(t)
	// a = l + w + tens(r) *** can check w previous
	// e = tens(a)

	int an = 0;
	for(d = 0; d < 10; d++) {
		h = d+d;
		for(n = 0; n < 10; n++) {
			t = n+n+(h/10);
			for(a = 0; a < 10; a++) {
				for(i = 0; i < 10; i++) {
					r = a+i + (t/10);
					for(l = 1; l < 10; l++) {
						for(w = 1; w < 10; w++) {
							if( a != (l+w)%10 ) continue;
							if( (int)( (l+w) /10) == 0) continue;
							// check if different
							set<int> s; s.insert(d%10); s.insert(h%10); s.insert(n%10); s.insert(t%10); s.insert(a%10); s.insert(i%10); s.insert(r%10); s.insert(l%10); s.insert(w%10); s.insert(1);
							if(s.size() != 10) continue;
							int ans = (h%10)+ 10*(t%10) + 100*(r%10) + 1000*(l+w);
							an += ans;
						}
					}
				}
			}
		}
	}

	cout << an << endl;

	return 0;
}
