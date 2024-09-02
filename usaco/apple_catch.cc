#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	set<pair<int,int>> cows; // t+x, n
	vector<array<int,3>> apples; // t, x, n
	int a,b,c,d;
	for(int i=0; i<n; i++) {
		cin>>a>>b>>c>>d;
		if(a == 1) cows.insert({b+c,d});
		else apples.push_back({b,c,d});
	}

	int cau=0;
	for(array<int,3> appl : apples) {
		int a = appl[0]-appl[1], b = appl[0]-appl[1], c = appl[2];
		while(c > 0) {
			cout << a << ' ' << b << ' ' << c << endl;
			auto it = cows.lower_bound({a, INT_MAX});
			if(it == cows.end()) auto it = cows.upper_bound({b, INT_MAX});
			if(it == cows.end()) break;

			cout << a << ' ' << b << ' ' << c << endl;
			cout << (*it).first << ' ' << (*it).second << endl;

			pair<int,int> cow = *it;
			int x = min(c, cow.second);
			cau += x;
			c -= x;
			cow.second -= x;
			if(cow.second != 0) {
				cows.erase(it);
				cows.insert(cow);
				break;
			} else {
				cows.erase(it);
			}
		}
	}

	cout << cau << endl;
}
