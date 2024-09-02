#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> a[5];

bool cmp(const int x, const int y) {
	int c = 0;
	for(int i = 0; i < 5; i++) c += (a[i][x] < a[i][y]);
	return c > 2;
}

int main() {
	cin >> n;
	int fin[n];
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < n; j++) {
			int x; cin >> x;
			a[i][x] = j;
			if(i == 0) fin[j] = x;
		}
	}

	sort(fin, fin+n, cmp);
	for(int i = 0; i < n; i++) cout << fin[i] << endl;
}
