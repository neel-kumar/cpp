#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int a[3] = {0, 0, 0};
	string s; cin>>s;
	int i = 0;
	for(char c : s) {
		if(c == '|') a[i]++;
		else i++;
	}

	if(a[0]+a[1]-a[2] == 2 && max(a[0], a[1]) > 1) {
		if(a[0] > 1) a[0]--;
		else a[1]--;
		a[2]++;
	} else if(a[0]+a[1]-a[2] == -2 && a[2] > 1) {
		a[0]++;
		a[2]--;
	} else if(a[0]+a[1]-a[2] != 0) {
		cout << "Impossible\n";
		return 0;
	}
	for(int k=0; k<a[0]; k++) cout << '|';
	cout << '+';
	for(int k=0; k<a[1]; k++) cout << '|';
	cout << '=';
	for(int k=0; k<a[2]; k++) cout << '|';
	cout << endl;
}
