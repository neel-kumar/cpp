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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,m; cin>>n>>m;
	int mt=0;
	for(int i=0;i<n;i++) {
		int a,b; cin>>a>>b;
		mt = max(mt, (int)ceil( (double)(m-a)/b) );
	}
	mt++;
	cout << mt << endl;
}
