#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		string x; cin >> x;
		if(x.size() > 10)
			cout << x[0] << (x.size()-2) << x[x.size()-1] << endl;
		else
			cout << x << endl;
	}
	return 0;
}
