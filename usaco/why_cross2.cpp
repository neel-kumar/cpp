#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("maxcross.in");
	//ifstream tin(".txt");
	ofstream fout("maxcross.out");
	int n, k, b; fin >> n >> k >> b;
	vector<int> ps(n+1);
	fill(ps.begin(), ps.end(), 0);
	for(int i = 0; i < b; i++) {
		int x; fin >> x;
		ps[x]++;
	}
	int curr = 0;
	for(int i = 0; i <= n; i++) {
		curr += ps[i];
		ps[i] = curr;
	}
	int ans = INT16_MAX;
	for(int i = 0; i <= n-k; i++)
		ans = min(ans, ps[i+k]-ps[i]);
	
	fout << ans << endl;
	return 0;
}
