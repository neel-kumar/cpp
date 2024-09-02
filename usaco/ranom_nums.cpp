#include <bits/stdc++.h>
using namespace std;

map<char, int> dig2num = {{'A',0}, {'B',1}, {'C',2}, {'D',3}, {'E',4}};
map<int, int> in2val = {{0,1}, {1,10}, {2,100}, {3,1000}, {4,10000}};

int count_sum(string t) {
	int sum = 0, max_in = 0;
	for(int i = (int)t.size()-1; i >= 0; i--) {
		int c = dig2num[t[i]];
		if(c < max_in) sum -= in2val[c];
		else sum += in2val[c];
	}
	cout << t << " :" << sum << "\n";
	return sum;
}

void solve() {
	string s; cin >> s;
	int fila[5][2] = {-1};
	int index = 0;
	for(char i : s) {
		if(fila[dig2num[i]][0] == -1) fila[dig2num[i]][0] = index;
		fila[dig2num[i]][1] = index;
	}

	vector<char> digis = {'A', 'B', 'C', 'D', 'E'};
	cout << fila[0][0] << " " << fila[0][1] << endl;
	int ans = 0;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; i < 2; j++) {
			if(s[fila[i][j]] == -1) continue;
			for(char d : digis) {
				string t = s;
				t[fila[i][j]] = d;
				ans = max(ans, count_sum(t));
			}
		}
	}
	cout << ans << "\n";
	return;
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	return 0;
}
