#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

long N, k;
long arr[200010];
multiset<long> top;
multiset<long> bottom;

void ins(long val) {         // insert val into sets
	long a = *bottom.rbegin();  // current median
	if (a < val) {
		top.insert(val);
		if (top.size() > k / 2) {
			bottom.insert(*top.begin());
			top.erase(top.find(*top.begin()));
		}
	} else {
		bottom.insert(val);
		if (bottom.size() > (k + 1) / 2) {
			top.insert(*bottom.rbegin());
			bottom.erase(bottom.find(*bottom.rbegin()));
		}
	}
}

void er(long val) {  // erase from sets
	if (top.find(val) != top.end()) top.erase(top.find(val));
	else bottom.erase(bottom.find(val));
	if (bottom.empty()) {
		bottom.insert(*top.begin());
		top.erase(top.find(*top.begin()));
	}
}

int find_cost() {
	int target = *bottom.rbegin();
	if(k%2 == 0) target = (target+*top.begin())/2;

	int cost = 0;
	for(long i : bottom)
		cost += target-i;
	for(long i : top)
		cost += i-target;
	return cost;
}

int main() {
	cin >> N >> k;
	for (int i = 0; i < N; i++) cin >> arr[i];
	bottom.insert(arr[0]);
	for (int i = 1; i < k; i++) ins(arr[i]);
	cout << find_cost() << " ";
	for (long i = k; i < N; i++) {
		if (k == 1) {
			ins(arr[i]);
			er(arr[i - k]);
		} else {
			er(arr[i - k]);
			ins(arr[i]);
		}
		// median if odd: bottom.rbegin()
		// ______ if even: bottom.rbegin() && top.begin()
		//cout << *bottom.rbegin() << " ";
		cout << find_cost() << " ";
	}
	cout << endl;
}
