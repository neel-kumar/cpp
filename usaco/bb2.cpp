#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    freopen("bb.in", "r", stdin);

	long lmx1, lmy1, lmx2, lmy2, cfx1, cfy1, cfx2, cfy2;
	cin >> lmx1 >> lmy1 >> lmx2 >> lmy2;
	cin >> cfx1 >> cfy1 >> cfx2 >> cfy2;

	if (cfx2 >= lmx2 && cfx1 <= lmx1) {
		if (cfy1 <= lmy1 && cfy2 > lmy1 && cfy2 <= lmy2) {
			cout << (lmy2-cfy2)*(lmx2-lmx1);
		} else if (cfy2 >= lmy2 && cfy1 > lmy1 && cfy1 <= lmy2) {
			cout << (cfy1-lmy1)*(lmx2-lmx1);
		}
	} else if (cfy2 >= lmy2 && cfy1 <= lmy1) {
		if (cfx1 <= lmx1 && cfx2 > lmx1 && cfx2 <= lmx2) {
			cout << (lmy2-lmy1)*(lmx2-cfx2);
		} else if (cfx2 >= lmx2 && cfx1 > lmx1 && cfx1 <= lmx2) {
			cout << (lmy2-lmy1)*(cfx1-lmx1);
		}
	} else {
		cout << (lmy2-lmy1)*(lmx2-lmx1);
	}
}
