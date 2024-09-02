#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200005;
const int INF = INT_MAX;
pair<int, int> t[4*MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)),
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

signed main() {
	int n, m; cin>>n>>m;
	for(int i=0; i<m; i++) {
		int a; cin>>a;
		update(1, 0, m-1, i, a);
	}

	int q; cin>>q;
	while(q--) {
		int x1, y1, x2, y2, k; cin>>x1>>y1>>x2>>y2>>k;
		x1--; y1--; x2--; y2--;
		if(abs(x2-x1)%k != 0 || abs(y2-y1)%k != 0) {
			cout << "NO\n";
			continue;
		}

		int y = n - (n-x1-1)%k;
		if(get_max(1, 0, m-1, min(y1, y2), max(y1, y2)).first >= y) cout << "NO\n";
		else cout << "YES\n";
	}
}
