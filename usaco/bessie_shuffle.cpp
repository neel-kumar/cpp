#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> def;

vector<int> comb_trans(vector<int> sequence, vector<int> permutation) {
	vector<int> newSequence(sequence.size());
	for(int i = 0; i < (int)sequence.size(); i++) {
		newSequence[i] = sequence[permutation[i]];
	}
	return newSequence;
}

vector<int> binpow(vector<int> a, long long b) {
    vector<int> res = def;
    while (b > 0) {
        if (b % 2)
            res = comb_trans(res, a);
        a = comb_trans(a, a);
        b /= 2;
    }
    return res;
}

vector<int> app_trans(vector<int> a, vector<int> b) {
	vector<int> sol(a.size());
	for(int i = 0; i < (int)a.size(); i++)
		sol[b[i]] = a[i];
	return sol;
}

int main() {
	int n, m, Q; scanf("%d %d %d", &n, &m, &Q);
	for(int i = 0; i < n; i++) def.push_back(i);
	vector<int> trans(n), top(n);
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		trans[i] = x-1;
	}
	for(int i = m; i < n; i++) trans[i] = i;
	top[0] = n-1;
	for(int i = 1; i < n; i++) top[i] = i-1;

	trans = comb_trans(top, trans);
	trans = binpow(trans, n-m+1);
	top = binpow(top, m-1);

	vector<int> ans = app_trans(def, trans);
	ans = app_trans(ans, top);
	reverse(ans.begin(), ans.end());
	while(Q--) {
		int x; cin >> x;
		printf("%d\n", ans[x-1]+1);
	}

return 0;
}
