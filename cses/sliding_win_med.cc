#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin>>n>>k;
	int a[n]; for(int i=0; i<n; i++) cin>>a[i];
	ordered_set<int> s;
	for(int i=0; i<k-1; i++) s.insert(a[i]);

	for(int i=k-1; i<n; i++) {
		s.insert(a[i]);
		if(i-k >= 0) s.erase(s.find_by_order(s.order_of_key(a[i-k])));
		cout << (*s.find_by_order((k-1)/2)) << ' ';
	}
	cout << endl;
}
