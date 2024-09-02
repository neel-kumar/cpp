/*
ID: n27k
TASK: task
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int main() {
	ifstream cin("cardgame.in");
	ofstream cout("cardgame.out");
	//ifstream tin(".txt");

	int n; cin >> n;
	vector<bool> used(2*n + 1);
	vector<int> ehigh(n/2), elow(n/2), bcards;
	for(int i = 0; i < n/2; i++) {
		cin >> ehigh[i];
		used[ehigh[i]] = true;
	}
	for(int i = 0; i < n/2; i++) {
		cin >> elow[i];
		used[elow[i]] = true;
	}
	for(int i = 1; i <= 2*n; i++) {
		if(!used[i])
			bcards.push_back(i);
	}
	sort(bcards.begin(), bcards.end());
	sort(ehigh.rbegin(), ehigh.rend());
	sort(elow.begin(), elow.end());

	int b = 0, ans = 0;
	for(auto i : elow) {
		if(bcards[b] < i) {
			b++;
			ans++;
		}
	}
	b = n-1;
	for(auto i : ehigh) {
		if(bcards[b] > i) {
			b--;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
