#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n%4 == 0) {
		cout << "YES\n";
		vector<int> ex, mid;
		int i = 1;
		while(i <= n) {
			ex.push_back(i);
			ex.push_back(i+3);
			mid.push_back(i+1);
			mid.push_back(i+2);
			i += 4;
		}
		cout << ex.size() << "\n";
		for(int j : ex) cout << j << " ";
		cout << "\n" << mid.size() << "\n";
		for(int j : mid) cout << j << " ";
	} else if(n%4 == 3) {
		cout << "YES\n";
		vector<int> ex = {1,2}, mid = {3};
		int i = 4;
		while(i <= n) {
			ex.push_back(i);
			ex.push_back(i+3);
			mid.push_back(i+1);
			mid.push_back(i+2);
			i += 4;
		}
		cout << ex.size() << "\n";
		for(int j : ex) cout << j << " ";
		cout << "\n" << mid.size() << "\n";
		for(int j : mid) cout << j << " ";
	} else cout << "NO";

	return 0;
}
