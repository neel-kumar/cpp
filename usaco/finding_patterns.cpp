#include <bits/stdc++.h>

using namespace std;
const int P = 29;
const long long MOD = 1e11 + 9;
set<long long> hashes; string n; int k;

void rollinghash_string(string n, int win_size) {
	long long curr = 0;
	long long ppow = 1;
	for(int i = win_size-1; i >= 0; i--) {
		ppow = ppow*P %MOD;
		curr += ppow * (int(n[i])-'a'+1);
		curr = curr %MOD;
	}

	hashes.insert(curr);
	for(int i = win_size; i < (int)n.size(); i++) {
		curr += (int(n[i])-'a'+1);
		curr -= (ppow * (int(n[i-win_size])-'a'+1))%MOD;
		curr = MOD + curr;
		curr *= P; curr = curr%MOD;
		hashes.insert(curr);
	}
}

long long hash_string(string n) {
	vector<long long> rolling_hash;
	long long hash= 0;
	long long ppow = 1;
	for(int i = n.size()-1; i >= 0; i--) {
		ppow = ppow*P %MOD;
		hash += ppow * (int(n[i])-'a'+1);
		hash = hash %MOD;
	}
	return hash;
}

int main() {
	cin >> n >> k;
	set<int> sizes;
	map<int, vector<string>> by_len;
	vector<string> order;
	map<string, bool> ans;
	while(k--) {
		string ki; cin >> ki;
		by_len[ki.size()].push_back(ki);
		order.push_back(ki);
	}
	for(auto i : by_len) {
		int length = i.first;
		rollinghash_string(n, length);
		for(string s : i.second)
			ans[s] = hashes.count(hash_string(s)) != 0;
	}
	for(string i : order) {
		if(ans[i]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
