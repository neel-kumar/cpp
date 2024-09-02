#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

int g,n;
vector<array<int,3>> crime, libi;

bool good(int a, int b) {
	if(a < 0 || a >= g) return false;
	int x=crime[a][1]-libi[b][1], y=crime[a][2]-libi[b][2], t=crime[a][0]-libi[b][0];
	return x*x + y*y > t*t;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> g >> n;
	crime.resize(g);
	libi.resize(n);
	for(int i = 0; i < g; i++)
		cin >> crime[i][1] >> crime[i][2] >> crime[i][0];
	for(int i = 0; i < n; i++)
		cin >> libi[i][1] >> libi[i][2] >> libi[i][0];
	sort(crime.begin(), crime.end());
	sort(libi.begin(), libi.end());

	int a=0, hi=0;
	for(int i = 0; i < n; i++) {
		while(hi < g && libi[i][0] > crime[hi][0])
			hi++;
		a += (good(hi-1,i) || good(hi,i));
		/* print(libi[i][0], crime[hi-1][0], crime[hi][0], hi, good(hi-1,i), good(hi,i)); */
	}
	cout << a << endl;
}
