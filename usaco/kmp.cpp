#include <bits/stdc++.h>
using namespace std;

string s1, s2;

vector<int> gen_lps(string s) {
	vector<int> lps(s.size());
	int j = 0, i = 1;
	lps[0] = 0;
	while(i < s.size()) {
		if(s[j] == s[i]) {
			j++;
			lps[i] = j;
			i++;
		} else {
			if(j == 0)
				lps[i] = 0, i++;
			else
				j = lps[j-1];
		}
	}
	return lps;
}

int main() {
	cin >> s1 >> s2;
	vector<int> lps = gen_lps(s2);

	int i = 0, j = 0, ans = 0;
	while(i < s1.size()) {
		if(s1[i] == s2[j]) {
			i++;
			j++;
		} else {
			if(j == 0)
				i++;
			else
				j = lps[j-1];
		}
		if(j == s2.size()) {
			ans++;
			j = lps[j-1];
		}
	}
	cout << ans << endl;

	return 0;
}
