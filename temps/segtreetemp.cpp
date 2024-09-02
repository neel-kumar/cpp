#include <bits/stdc++.h>
using namespace std;

// seg_tree and methods
int* st;
int* lp;
int s;

// segtree func (ex: min, max, sum)
int f(int x, int y) {
	// this is min
	return min(x, y);
}

void initR(int a[], int node, int l, int r) {
	if(l == r) { st[node] = a[l]; return; }
	int m = (l+r)/2;
	initR(a, node*2, l, m);
	initR(a, node*2+1, m+1, r);
	st[node] = f(st[node*2], st[node*2+1]);
}

void init(int a[], int S) {
	st = new int[S*4];
	lp = new int[S*4];
	memset(lp, 0, S*4);
	s = S;
	initR(a, 1, 0, s-1);
}

void print(int node=1, int l=0, int r=s-1) {
	if(l == r) { cout << st[node] << " "; return; }
	int m = (l+r)/2;
	if(node == 1) cout << endl;
	cout << st[node] << " ";
	print(node*2, l, m);
	print(node*2+1, m+1, r);
}

void upd1(int p, int val, int node=1, int l=0, int r=s-1) {
	if(l == r) { st[node] = val; return; }
	int m = (l+r)/2;
	if(p <= m) upd1(p, val, node*2, l, m);
	else upd1(p, val, node*2+1, m+1, r);
	st[node] = f(st[node*2], st[node*2+1]);
}

int query(int l, int r, int node=1, int cl=0, int cr=s-1) {
	lp[node*2] += lp[node];
	lp[node*2+1] += lp[node];
	st[node] += lp[node]; lp[node] = 0;
	if(cl == l && cr == r) return st[node];
	int m = (cl+cr)/2;
	if(r <= m) return query(l, r, node*2, cl, m);
	else if(l > m) return query(l, r, node*2+1, m+1, cr);
	else return f(query(l, m, node*2, cl, m), query(m+1, r, node*2+1, m+1, cr));
}

// lazy prop
void upd_range(int l, int r, int u, int node=1, int cl=0, int cr=s-1) {
	lp[node*2] += lp[node];
	lp[node*2+1] += lp[node];
	st[node] += lp[node]; lp[node] = 0;
	if(cl == l && cr == r) {
		lp[node*2] += u;
		lp[node*2+1] += u;
		st[node] += u;
		return;
	}
	int m = (cl+cr)/2;
	if(r <= m) upd_range(l, r, u, node*2, cl, m);
	else if(l > m) upd_range(l, r, u, node*2+1, m+1, cr);
	else { upd_range(l, m, u, node*2, cl, m); upd_range(m+1, r, u, node*2+1, m+1, cr); }
	st[node] = f(st[node*2], st[node*2+1]);
}

signed main() {

	return 0;
}
