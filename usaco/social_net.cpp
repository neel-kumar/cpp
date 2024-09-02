#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	deque<int> msg_list;
	set<int> curr_msg;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(curr_msg.count(x) != 0) continue;
		if((int)curr_msg.size() == k) {
			int msg_back = msg_list.back();
			curr_msg.erase(curr_msg.find(msg_back));
			msg_list.pop_back();
		}
		curr_msg.insert(x);
		msg_list.push_front(x);
	}

	cout << msg_list.size() << endl;
	while(!msg_list.empty()) {
		int x = msg_list.front();
		cout << x << " ";
		msg_list.pop_front();
	}

	return 0;
}
