#include <bits/stdc++.h>


using namespace std;

using ll = long long;
int N, A, B;

int main() {
	cin >> N >> A >> B;

	vector<long long> pfx(N+1);

	for(int i = 1; i <= N; i++) {
		int a; cin >> a;
		pfx[i] = a + pfx[i-1];
    }

    ll ans = INT64_MIN;
	multiset<ll> ms;
	for(int i = A; i <= N; ++i) {
		if(i > B) ms.erase(ms.find(pfx[i-B-1]));
		ms.insert(pfx[i-A]);
		ans = max(ans, pfx[i]-*ms.begin());

	}
	cout << ans << "\n";

    return 0;
}
