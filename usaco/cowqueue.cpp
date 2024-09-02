#include <map>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("cowqueue.in", "r", stdin);
	map<int, int> a2qt;
	int ncows;
	cin >> ncows;
	int ats[ncows];

	for(int i = 0; i < ncows; i++) {
		int at, qt;
		cin >> at >> qt;
		ats[i] = at;
		a2qt[at] = qt;
	}
	sort(ats, ats + ncows);

	int ans = 0;
	for(int at : ats) {
		if(ans < at) {
			ans = at + a2qt[at];
		} else {
			ans += a2qt[at];
		}
	}
	cout << ans;
}
