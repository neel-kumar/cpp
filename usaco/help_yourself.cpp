/*
ID: n27k
TASK: help
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
	ifstream fin("help.in");
	ofstream fout("help.out");
	int n; fin >> n;
	const int MOD = 1e9+7;
	vector<ii> v(n);
	for(int i = 0; i < n; i++) fin >> v[i].first >> v[i].second;
	vi pow2(n); pow2[0] = 1; for(int i = 1; i < n; i++) pow2[i] = 2*pow2[i-1]%MOD;
	vi over(2*n+1);
	for(auto t : v) {over[t.first]++; over[t.second]--; }
	for(int i = 1; i < 2*n+1; i++) over[i] += over[i-1];
	int ans = 0; for(auto t : v) ans = (ans+pow2[n-1-over[t.first-1]])%MOD;
	fout << ans << endl;
	return 0;
}
