#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, d;
vector<int> x;

bool f(double t) {
	double itv = t+ ((double)d);
	vector<pair<double,double>> xi;
	for(int i : x) { xi.push_back({i-itv, i+itv}); }

	vector<int> fin;
	int l = 0, r = 0;
	for(int i = 0; i < n; i++) {
		while(l <= i && xi[l].second < xi[i].first) l++;
		while(r < n-1 && xi[i].second >= xi[r+1].first) r++;
		if(r == l) return false;
		fin.push_back(r-l);
		/* cout << l << ' ' << i << ' ' << r << endl; */
	}

/* 	for(int i = 0; i < n; i++) cout << fin[i]; */
/* 	cout << endl; */
/* 	for(int i = 0; i < n; i++) cout << "(" << xi[i].first << ',' << xi[i].second << ") "; */
/* 	cout << endl; */

	for(int i = 2; i < n; i++) if(fin[i-2]==1 && fin[i-1]==2 && fin[i]==1) return false;
	return true;
}

void solve() {
	cin>>n>>d;
	x.resize(n); for(int i = 0; i < n; i++) cin>>x[i];
	sort(x.begin(), x.end());

    double l=0.0,r=1000000000.0;
    /* cout << l << " " << r; */
    while((r-l)>0.000000001){
        double mid = (double)((l+r)/2);

		bool works = f(mid);
        cout << mid << ' ' << works << endl;

        if(works) r=mid;
        else l=mid+0.000000001;
    }
	cout << setprecision(9) << l << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
