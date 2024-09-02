#include <bits/stdc++.h>

using namespace std;

int N, T;
int d[100005];

bool f2(int k) {
	int last = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 0; i < N; i++) {
		if((int)q.size() == k) { last = q.top(); q.pop(); }
		if(last + d[i] > T) return false;
		q.push(last + d[i]);
	}
	return true;
}

bool f1(int nc) {
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 0; i < nc; i++) q.push(d[i]);

	for(int i = nc; i < N; i++) {
		int front = q.top();
		if(front + d[i] > T) return false;
		q.pop();
		q.push(front + d[i]);
	}
	return true;
}

bool f(int nc) {
	vector<int> temp;
	// copy(d.begin(), d.end(), back_inserter(temp));
	copy(d, d + nc, back_inserter(temp));
	make_heap(temp.begin(), temp.end());

	for(int i = nc; i < N; i++) {
		int front = temp.front();
		pop_heap(temp.begin(), temp.end());
		temp.pop_back();
		if((front + d[i]) < (T*-1)) return false;
		temp.push_back(front + d[i]);
		push_heap(temp.begin(), temp.end());
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
		d[i] = (x*(-1));
	}
	cout << first_true(1, N);

	return 0;
}
