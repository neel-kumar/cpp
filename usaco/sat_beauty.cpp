#include <iostream>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int n;
int a[100000];
int f[101][100001];

signed main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++) {
	f[a[i]][i+1]++;
	for(int j=0;j<=100;j++) f[j][i+1]+=f[j][i];
    }

    double m = INT_MAX;
    int L=-1,R=-1;
    for(int u=1;u<=100;u++) {
	int l=0,c[101];
	double cur=0.0;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++) {
	    if(!c[a[i]])
		cur++;
	    c[a[i]]++;
	    while(cur>u) {
		c[a[l]]--;
		if(!c[a[l]]) cur--;
		l++;
	    }
	    cerr << m << ' ' << cur/(i-l+1) << ' ' << l << ' ' << i << endl;

	    if(m > (cur/(i-l+1)) || (m >= double(cur/(i-l+1)) && l < L)) {
		L=l;
		R=i;
		m = (cur/(i-l+1));
	    }
	}
    }
    cout << L+1 << " " << R+1 << endl;
}
