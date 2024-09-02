#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> lng, shrt;

bool check(int dist) {
	int j = 0;
	for(int i = 0; i < (int)shrt.size(); i++) {
		while(abs(shrt[i]-lng[j]) > dist && j < lng.size()) j++;
		if(j >= (int)lng.size()) return false;
		j++;
		//cout << i << " " << j << endl;
	}
	return true;
}

int main() {
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	if(n < m) shrt = a, lng = b;
	else shrt = b, lng = a;
	sort(shrt.begin(), shrt.end()); sort(lng.begin(), lng.end());

	int l = 1, r = 1e9+1;
	while(l < r) {
		int mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << endl;
	return 0;
}
