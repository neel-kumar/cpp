#include <bits/stdc++.h>
#define int long long
using namespace std;

int setBitNumber(int n)
{
    // calculate the  number
    // of leading zeroes
    int k = __builtin_clz(n);

    // To return the value
    // of the number with set
    // bit at (31 - k)-th position
    // assuming 32 bits are used
    return 1 << (31 - k);
}

void solve() {
	int n, k; cin >> n >> k;
	int ans[(int)log2(n)+1]; memset(ans, 0, sizeof ans);

	if(k == 1) {
		cout << (int)log2(n)+1 << endl << "3 ";
		for(int i = 1; i < (int)log2(n)+1; i++) {
			cout << ((int)pow(2, i)) << " ";
		}
		cout << endl;
		return;
	} else if(k == 2) {
		cout << (int)log2(n) << endl << "1 ";
		for(int i = 2; i < (int)log2(n)+1; i++) {
			cout << ((int)pow(2, i)) << " ";
		}
		cout << endl;
		return;
	}

	int t = k;
	while(t <= n) {
		int i = (int)log2(setBitNumber(t));
		ans[i] -= 1;
		t += (int)pow(2, i+1);
	}

	cout << (int)log2(n)+1 << endl;
	for(int i = 0; i < (int)log2(n)+1; i++) {
		cout << ((int)pow(2, i) + ans[i]) << " ";
	}
	cout << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
