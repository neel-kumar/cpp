#include <bits/stdc++.h>

using namespace std;

struct lli {
	int p, n, v; // refrences are really just indecies for the list
};
const int PRIME = 10007;
vector<lli> hash_ll;
int N;

void init_ll() {
	lli st;
	st.p = -1;
	st.n = -1;
	st.v = -1;

	for(int i = 0; i < PRIME; i++) {
		hash_ll.push_back(st);
	}
}

void hash_add(int val) {
	lli new_st;
	new_st.n = -1;
	new_st.v = val;
	int curr = val%PRIME;

	int count = -1;

	while(hash_ll[curr].n != -1) {
		++count;
		
		if(hash_ll[curr].v == val)
			return;
		curr = hash_ll[curr].n;
	}
	if(hash_ll[curr].v == val) return;
	hash_ll[curr].n = hash_ll.size();
	hash_ll.push_back(new_st);
}

int main() {
	init_ll();
	cin >> N;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		hash_add(x);
	}
	cout << hash_ll.size()-PRIME;
	return 0;
}
