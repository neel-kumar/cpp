#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x; cin >> n >> x;
	vector<int> algos(n);
	for(int i = 0; i < n; i++)
		cin >> algos[i];
	sort(algos.begin(), algos.end());
	int i = 0;
	while(i < n && x-algos[i] >= 0) {
		x -= algos[i];
		i++;
	}
	cout << i << endl;
	return 0;
}
