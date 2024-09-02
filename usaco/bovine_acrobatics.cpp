#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

int n,m,k;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i].f >> a[i].s;

	sort(a.rbegin(), a.rend());

	int ans=0, tt=0;
	deque<pair<int,int>> q;
	for(auto i : a) {
		int used=0;
		while(!q.empty() && q.front().f >= i.f+k && used < i.s) {
			if(q.front().s > i.s-used) {
				q.front().s -= i.s-used;
				used = i.s;
				break;
			} else {
				used += q.front().s;
				q.pop_front();
			}
		}

		ans += used;
		assert(used <= i.s);
		assert(tt <= m);
		if(used < i.s) {
			ans += min(i.s-used, m-tt);
			q.push_back({i.f, min(i.s-used, m-tt)+used});
			tt+=i.s-used;
			tt=min(m,tt);
		} else {
			q.push_back({i.f, used});
		}
	}
	cout << ans << endl;
}
