#include <bits/stdc++.h>

using namespace std;

int N, T;
int d[100005];

bool f(int k) {
	int curr_last = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 0; i < N; i++) {
		if((int)q.size() == k) {
			curr_last = q.top();
			q.pop();
		}
		if(curr_last + d[i] > T) return false;
		q.push(curr_last + d[i]);
	}
	return true;
}

int first_true(int lo, int hi) {
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid) && (mid == lo || !f(mid-1))) {
			return mid;
		} else if (f(mid)) {
			hi = mid-1;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main () {
	cin >> N >> T;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		d[i] = x;
	}
	cout << first_true(1, N);

	return 0;
}
