#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,k; cin >> n >> k;
	int a[n], b[n];
	set<int> oa,ob,shared;
	for(int i = 0; i < k; i++) {
		cin >> a[i];
		oa.insert(a[i]);
	}

	for(int i = 0; i < k; i++) {
		cin >> b[i];
		if(oa.count(b[i])) shared.insert(b[i]), oa.erase(b[i]);
		else ob.insert(a[i]);
	}

	if(shared.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	int st = *shared.begin();
	int si, ai;
	for(int i = 0; i < k; i++) {
		if(b[i] == st) {
			si = i;
			break;
		}
	}
	for(int i = 0; i < k; i++) {
		if(a[i] == st) {
			ai = i;
			break;
		}
	}
	rotate(b, b+si, b+k);
	rotate(a, a+ai, a+k);

	// counting thingy
	int ca[n+1], cf[n+1];
	for(int i = 0; i < k; i++) {
		if(shared.count(a[i])) ca[a[i]] = i;
	}
	for(int i = 0; i < k; i++) {
		if(shared.count(b[i])) cf[b[i]] = (ca[b[i]]-i+k)%(k);
	}
	int f[n+1];
	memset(f, 0, sizeof(f));
	int ans = 0;
	for(int i = 1; i < n+1; i++) {
		if(shared.count(i)) {
			f[cf[i]]++;
			ans = max(f[cf[i]], ans);
		}
	}
	int rans = (ans+ (n-shared.size()-oa.size()-ob.size()));


	reverse(b+1, b+k);

	for(int i = 0; i < k; i++) {
		if(shared.count(a[i])) ca[a[i]] = i;
	}
	for(int i = 0; i < k; i++) {
		if(shared.count(b[i])) cf[b[i]] = (ca[b[i]]-i+k)%(k);
	}
	memset(f, 0, sizeof(f));
	ans = 0;
	for(int i = 1; i < n+1; i++) {
		if(shared.count(i)) {
			f[cf[i]]++;
			ans = max(f[cf[i]], ans);
		}
	}
	rans = max(rans, (ans+ (int)(n-shared.size()-oa.size()-ob.size())));
	cout << rans << endl;
}
