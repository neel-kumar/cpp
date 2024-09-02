#include <bits/stdc++.h>
using namespace std;

int calcn(int n) {
	int newn = n-1;
	int a = newn * (newn+1);
	return a/2;
}

int main() {
	string s; cin >> s;
	int sol = calcn(s.size()) +1;
	map<char, int> charmap;
	for(char i : s) charmap[i]++;

	string abcs = "abcdefghijklmnopqrstuvwxyz";
	for(char let : abcs) if(charmap.count(let)) sol -= calcn(charmap[let]);
	cout << sol << endl;

	return 0;
}
