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

	char digs[5]={'0','2','4','6','8'};
	int n; cin >> n;
	vector<int> a = {0};
	for(int i=0;i<n-1;i++) {
		a[0]++;
		int j=0;
		while(j < a.size() && a[j]==5) {
			a[j]=0;
			a[j+1]++;
			j++;
		}
		if(j==a.size()) a.push_back(1);
	}
	for(int i=a.size()-1;i>=0;i--)
		cout << digs[a[i]];
	cout<<'\n';
}
