#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
bool a[N];

signed main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	if(n == 1) { cout << "1\n"; return 0; }

	vector<int> seg;
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		cnt += a[i]!=a[i-1];
		if(a[i]==a[i-1]) {
			seg.push_back(cnt);
			cnt = 1;
		}
	}
	seg.push_back(cnt);

	int M = 0;
	for(int i = 0; i < seg.size(); i++) {
        int nsum = seg[i];
        if(i-1 >= 0) nsum += seg[i-1];
        if(i+1 < n) nsum += seg[i+1];
		M = max(nsum, M);
	}
	cout << M << endl;
}

