#include <bits/stdc++.h>

using namespace std;

int main() {
	string n; cin >> n;
	const int P = 31;
	const int MOD = 1e9+7;

	long long bhash = 0, ehash = 0, ppow = 1;
	for(int i = 0; i < n.size()-1; i++) {
		ppow *= P; ppow = ppow%MOD;
		bhash += ppow * (int(n[i])-'a'+1); bhash = bhash%MOD;
		ehash += (int(n[n.size()-1-i])-'a'+1); ehash = ehash%MOD;
		ehash *= P; ehash = ehash%MOD;
		//printf("B%d E%d\n", bhash, ehash);
		if(ehash == bhash)
			cout << i+1 << " ";
	}
	return 0;
}
