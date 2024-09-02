#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1e5;
int base[MAXN], ns = 0;
stack<int> stacks[MAXN];

int first_true(int x) {
	for(int i = 0; i < ns; i++) {
		if(base[i] > x)
			return i;
	}
	return ns;
}

int main() {
	cin >> n;
	int placed = INT8_MAX;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x < placed) {
			cout << i << endl;
			return 0;
		}
		int si = first_true(x);
		if(si == ns) {
			ns++;
			stacks[si].push(x);
		} else {
			while(!stacks[si].empty() && stacks[si].top() < x) {
				placed = min(placed, stacks[si].top());
				stacks[si].pop();
			}
			stacks[si].push(x);
		}
	}
	return 0;
}
