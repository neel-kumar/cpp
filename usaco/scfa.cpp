#include <iostream>
#include <vector>
#include <set>

using namespace std;

int64_t ans = 0;
int N;

// using a sorted set
void add_contribution(const vector<int>& h) {
	vector<int> with_h(N+1);
	for (int i = 0; i < N; ++i) with_h[h[i]] = i;
	set<int> present;
	for (int cur_h = N; cur_h; --cur_h) {
		auto it = present.insert(with_h[cur_h]).first;
		if (next(it) != end(present)) ans += *next(it)-*it+1;
	} // the cow at position with_h[cur_h] can throw to the next cow after it
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	vector<int> h(N); for (int& i: h) cin >> i;
	add_contribution(h);
	reverse(begin(h), end(h));
	add_contribution(h);
	cout << ans << "\n";
}

