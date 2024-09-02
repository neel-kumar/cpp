#include <bits/stdc++.h>

using namespace std;

int bessie['z' + 1];

void init_bessie() {
	bessie['b'] = 1;
	bessie['e'] = 2;
	bessie['s'] = 2;
	bessie['i'] = 1;
}

int find_left(string& s, const int r) {
	init_bessie();
	int tofind = 6; // length of bessie
	// Move r as far as possible to encompass bessie
	int l = r;
	while(l >= 0) {
		if(bessie[s[l]] > 0) {
			bessie[s[l]]--;
			--tofind;
		}
		if(tofind == 0) break;
		l--;
	}
	return l;
}

int main() {
	// std::string s = "bessie";
	// std::string s = "abessie";
	// std::string s = "bessieb";
	// std::string s = "bessiebessie";
	string s = "abcdefghssijebessie";
	const int n = s.size();

	int r = 0;
	while(r < n) {
		init_bessie();
		int tofind = 6; // length of bessie
		// Move r as far as possible to encompass bessie
		while(r < n && tofind > 0) {
			if(bessie[s[r]] > 0) {
				bessie[s[r]]--;
				--tofind;
			}
			r++;
		}

		if(tofind == 0) {
			int l = find_left(s, r - 1);
			cout << "l = " << l << ", r = " << (r - 1) << endl;
		}
	}
}

