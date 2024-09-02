#include <bits/stdc++.h>
#define int long long
using namespace std;

struct iv {
	int time;
	int lft;
	int f;
	iv(int t, int l, int fn): time(t), lft(l), f(fn) {}
};

struct Compare
{
    bool operator() (iv& a, iv& b)
    {
		return a.time > b.time;
    }
};

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1LL); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0LL ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

signed main() {
	int n,k; cin>>n>>k;
	vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
	priority_queue<iv, vector<iv>, Compare> pq;
	for(int i=0;i<k;i++) {
		iv x(a[i],1,i);
		pq.push(x);
	}

	DSU dsu = DSU(k);
	for(int j=k;j<n;j++) {
		int i=a[j];
		iv c = pq.top(); pq.pop();
		while(pq.size() && c.time == pq.top().time) {
			iv cadd = pq.top(); pq.pop();
			c.lft+=cadd.lft;
			dsu.unite(c.f,cadd.f);
		}
		if(c.lft > 1) {
			pq.push(iv(c.time,c.lft-1,c.f));
			pq.push(iv(c.time+i,1,c.f));
		} else {
			pq.push(iv(c.time+i,c.lft,c.f));
		}
	}

	iv fin = pq.top();
	cout << fin.time << endl;
	for(int i=0;i<k;i++)
		cout << (dsu.same_set(i,fin.f)?'1':'0');
	cout << endl;
}
