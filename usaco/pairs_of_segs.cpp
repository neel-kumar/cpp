#include <bits/stdc++.h>
using namespace std;

bool do_intersect(pair<int, int> a, pair<int, int> b) {
	if(a.second >= b.first && a.second <= b.second) return true;
	else if(b.second >= a.first && b.second <= a.second) return true;
	return false;
}

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> segs(n);
	for(int i = 0; i < n; i++) {
		cin >> segs[i].first >> segs[i].second;
	}
	vector<pair<int, int>> inter;
	set<pair<int, int>> inter_set;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			pair<int, int> pos_pair = make_pair(min(segs[i].first, segs[j].first), max(segs[i].second, segs[j].second));
			if(do_intersect(segs[i], segs[j]) && inter_set.count(pos_pair) == 0) {
				inter.push_back(pos_pair);
				inter_set.insert(pos_pair);
			}
		}
	}
	sort(inter.begin(), inter.end());

	// max intersections where none inter
	int cnt_pairs = 0;
	sort(inter.begin(), inter.end(), comp);
	int last_pos = -1;
	for(auto x : inter)
		if(x.first > last_pos) {
			cnt_pairs++;
			last_pos = x.second;
		}
		
	cout << n - 2*cnt_pairs << endl;
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	return 0;
}
