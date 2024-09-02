/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
/* #define int long long */
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef bitset<1000000001> bs;
/*
 * bs[i]        =>  sett.count(i)
 * bs.sett(i)    =>  sett.insert(i)
 * bs.resett(i)  =>  sett.erase(i)
 * bs.count()   =>  sett.size()
 */
using ld = long double;
using ll = long long;
#define f first
#define s second

const int maxN = 2e5 + 5;
int N;
int a[maxN];

struct node {
	ll val;
	ll lzAdd;
	ll lzSet;
	node(){};
} tree[maxN << 2];

#define lc p << 1
#define rc (p << 1) + 1

inline void pushup(int p) {
	tree[p].val = tree[lc].val + tree[rc].val;
	return;
}

void pushdown(int p, int l, int mid, int r) {
	// lazy: range sett
	if (tree[p].lzSet != 0) {
		tree[lc].lzSet = tree[rc].lzSet = tree[p].lzSet;
		tree[lc].val = (mid - l + 1) * tree[p].lzSet;
		tree[rc].val = (r - mid) * tree[p].lzSet;
		tree[lc].lzAdd = tree[rc].lzAdd = 0;
		tree[p].lzSet = 0;
	} else if (tree[p].lzAdd != 0) {  // lazy: range add
		if (tree[lc].lzSet == 0) tree[lc].lzAdd += tree[p].lzAdd;
		else {
			tree[lc].lzSet += tree[p].lzAdd;
			tree[lc].lzAdd = 0;
		}
		if (tree[rc].lzSet == 0) tree[rc].lzAdd += tree[p].lzAdd;
		else {
			tree[rc].lzSet += tree[p].lzAdd;
			tree[rc].lzAdd = 0;
		}
		tree[lc].val += (mid - l + 1) * tree[p].lzAdd;
		tree[rc].val += (r - mid) * tree[p].lzAdd;
		tree[p].lzAdd = 0;
	}
	return;
}

void build(int p, int l, int r) {
	tree[p].lzAdd = tree[p].lzSet = 0;
	if (l == r) {
		tree[p].val = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(p);
	return;
}

void add(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val += (r - l + 1) * val;
		if (tree[p].lzSet == 0) tree[p].lzAdd += val;
		else tree[p].lzSet += val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	add(lc, l, mid, a, b, val);
	add(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

void sett(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val = (r - l + 1) * val;
		tree[p].lzAdd = 0;
		tree[p].lzSet = val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	sett(lc, l, mid, a, b, val);
	sett(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

ll query(int p, int l, int r, int a, int b) {
	if (a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[p].val;
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	return query(lc, l, mid, a, b) + query(rc, mid + 1, r, a, b);
}

signed main() {
	/*
	 * range update, range sum, range set
	 *
	 * build tree from a[]	   build(1, 1, N);
	 * add x to tree [a,b]     add(1, 1, N, a, b, x);
	 * set tree [a,b] to x     sett(1, 1, N, a, b, x);
	 * query sum [a,b]         query(1, 1, N, a, b);
	 */
}
