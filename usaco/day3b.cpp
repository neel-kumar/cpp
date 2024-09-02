#include <bits/stdc++.h>
using namespace std;

// 1 = angle
// 0 = straight
int n;
vector<int> water[2];

bool rec(int x, int y) {
	if(x == 0 && y == 0) return true;
	if(x == 0 && y == -1) return true;
	if(x < 0 || x > 1 || y < 1 || y > n) return false;

	bool if_straight = (water[x][y] == 0) && (rec(x, y-1));
	bool if_angle = (water[x][y] == 1) && (water[!x][y] == 1) && (rec(!x, y-1));
	return if_angle || if_straight;
}

int main() {
	int t; cin >> t;
	while(t--) {
		// input
		cin >> n;
		water[0].clear(), water[1].clear();
		water[0].push_back(-1); water[1].push_back(-1);
		for(int i = 0; i < n; i++) {
			char c; cin >> c;
			int x = c-'1'+1;
			if(x > 2) water[0].push_back(1);
			else water[0].push_back(0);
		}
		for(int i = 0; i < n; i++) {
			char c; cin >> c;
			int x = c-'1'+1;
			if(x > 2) water[1].push_back(1);
			else water[1].push_back(0);
		}

		if(rec(1, n)) cout << "YES\n";
		else cout << "NO\n";

	}
	return 0;

}
