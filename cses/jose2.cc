#include <bits/stdc++.h>
#define int long long
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;
// Declaring ordered_set
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
	int n, x; cin >> n >> x;
	if(x == 0) {
		for(int i=1; i<=n; i++) cout << i << " ";
		cout << endl;
		return 0;
	}

	vector<int> ret;
	ordered_set<int> avail;
	for(int i=0; i<n; i++) avail.insert(i+1);

	for(int i = n, j = 0; i>1; i--) {
		int newpos = (avail.order_of_key(j) + x) % i;
		ret.push_back(*avail.find_by_order(newpos));
		avail.erase(avail.find_by_order(newpos));
		newpos %= i-1;
		j = *avail.find_by_order(newpos);
	}
	ret.push_back(*avail.find_by_order(0));

	for(int i : ret) cout << i << " ";
	cout << endl;
	return 0;
}
