#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll calcn(ll n) {
	ll newn = n-1;
	ll a = newn * (newn+1);
	return a/2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	ll sol = calcn(s.size()) +1;
	map<char, ll> charmap;
	for(char i : s) charmap[i]++;

	string abcs = "abcdefghijklmnopqrstuvwxyz";
	for(char let : abcs) if(charmap.count(let)) sol -= calcn(charmap[let]);
	cout << sol << "\n";

	return 0;
}
