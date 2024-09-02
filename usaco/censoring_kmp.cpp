#include <bits/stdc++.h>
using namespace std;

string s, blackl;

void LPSArray(string pattern, int M, int* lps);

string KMPSearch(string pattern, string txt) {
	int M = pattern.size();

	int lps[M];

	LPSArray(pattern, M, lps);

	int i = 0; 
	int j = 0; 
	int rewind[txt.size()*2]; // i, j
	while (i < (int)txt.size()) {
		rewind[i] = j;
		if (pattern[j] == txt[i]) {
			j++;
			i++;
			if(j == M) {
				txt = txt.substr(0, i-M) + txt.substr(i, txt.size()-i);
				i -= M+1;
				i = max(i, 0);
				j = rewind[i];
			}
		} else {
			if (j != 0) j = lps[j - 1];
			else { i++; }
		}
	}
	return txt;
}

void LPSArray(string pattern, int M, int* lps) {
	int len = 0;
	lps[0] = 0; 
	int i = 1;
	while (i < M) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main() {
	cin >> s >> blackl;
	cout << KMPSearch(blackl, s) << endl;

	return 0;
}
