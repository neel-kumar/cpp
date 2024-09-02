#include <bits/stdc++.h>
using namespace std;

#define ll long long

// seg_tree and methods
ll* st;
ll* lp;
int s;

// segtree func (ex: min, max, sum)
ll f(ll x, ll y) {
	// this is min
	return min(x, y);
}

void initR(ll a[], int node, int l, int r) {
	if(l == r) { st[node] = a[l]; return; }
	int m = (l+r)/2;
	initR(a, node*2, l, m);
	initR(a, node*2+1, m+1, r);
	st[node] = f(st[node*2], st[node*2+1]);
}

void init(ll a[], ll S) {
	st = new ll[S*4];
	lp = new ll[S*4];
	memset(lp, 0, S*4);
	s = S;
	initR(a, 1, 0, s-1);
}

void push(int l, int r, int p) {
	if(lp[p] == 0) return;
	st[p] += lp[p];
	if(l != r) {
		lp[p*2] += lp[p];
		lp[p*2+1] += lp[p];
	}
	lp[p] = 0;
}

void upd1(int p, ll val, int node=1, int l=0, int r=s-1) {
	push(l, r, node);
	if(l == r) {
		lp[node] += val;
		push(l, r, node);
		return;
	}
	int m = (l+r)/2;
	if(p <= m) upd1(p, val, node*2, l, m);
	else upd1(p, val, node*2+1, m+1, r);
	st[node] = f(st[node*2], st[node*2+1]);
}

ll query(int l, int r, int node=1, int cl=0, int cr=s-1) {
	push(l, r, node);
	if(l == cl && r == cr) return st[node];
	assert(cl <= l && cr >= r);
	int m = (cl+cr)/2;
	if(r <= m) return query(l, r, node*2, cl, m);
	else if(l > m) return query(l, r, node*2+1, m+1, cr);
	else return f(query(l, m, node*2, cl, m), query(m+1, r, node*2+1, m+1, cr));
}

void updr(int i, int j, ll x, int p = 1, int l = 0, int r = s-1) {
    push(p, l, r);
    if (l > j || r < i) return;
    else if (i <= l && r <= j) {
        lp[p] += x;
        push(l, r, p);
    } else {
        int m = (l + r) / 2;
        updr(i, j, x, 2 * p, l, m);
        updr(i, j, x, 2 * p + 1, m + 1, r);
        st[p] = f(st[2 * p], st[2 * p + 1]);
    }
}

signed main() {
	int n, m;
	cin >> n >> m;
	ll days[n];
	for(ll i = 0; i < n; i++) cin >> days[i];
	init(days, n);

	for(int i = 1; i <= m; i++) {
		int barns, st, en; cin >> barns >> st >> en;
		st--; en--;
		updr(st, en, -barns);
		//for(int j = st; j <= en; j++) upd1(j, -barns);
		if(query(0, n-1) < 0) { cout << "-1\n" << i << endl; return 0; }
	}
	cout << "0\n";

	return 0;
}
