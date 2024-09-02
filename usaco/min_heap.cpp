#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(8);
	q.push(4);
	q.push(5);
	q.push(8);
	q.pop();
	q.push(1);
	q.push(3);
	while(!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}

	return 0;
}
