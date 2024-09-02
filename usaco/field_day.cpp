#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int N,C; cin >> C >> N;
	int d[1<<C]; for(int i=0; i<(1<<C); i++) d[i]=-1;
	vector<int> T;
	for(int i=0;i<N;i++) {
		char s[C]; cin >> s;
		for(int j=0;j<C;j++)
			s[j] = (s[j]=='G'?'0':'1');
		char* end;
		T.push_back(strtol(s,&end,2));
		assert(T[T.size()-1]<(1<<C));
		/* cerr << s << ' ' << T[T.size()-1] << endl; */
	}

	queue<int> q;
	for(int i=0;i<N;i++) {
		q.push(T[i]);
		d[T[i]]=0;
	}
	while(!q.empty()) {
		int x=q.front(); q.pop();
		assert(d[x]<=C);
		for(int i=0; i<C; i++) {
			int newx = x^(1<<i);
			if(d[newx] == -1) {
				/* cerr << x << ' ' << newx << endl; */
				d[newx] = d[x]+1;
				q.push(newx);
			}
		}
	}

	// final constr
	for(int i=0; i<N; i++) {
		int rt = ((1<<C)-1)^T[i]; // rev bits
		/* cerr << d[T[i]] << ' ' << rt << ' ' << d[rt] << endl; */
		cout << C-d[rt] << endl;
	}
}
