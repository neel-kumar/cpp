#include <iostream>
using namespace std;

int solve(int d, int ends) {
	int currspeed = 0;
	int distrem = d;
	int time = 0;
	int dist2ends = 0;
}

int main() {
	freopen("race.in", "r", stdin);
	int d, n;
	cin >> d >> n;
	for (int i = 0; i < n; i++) {
		int ends;
		cin >> ends;
		cout << solve(d, ends) << endl;	
	}
}
