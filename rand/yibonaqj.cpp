#include <bits/stdc++.h>
#define int long long
using namespace std;

int mn;

void f(int x) {
	if(x>=0) mn=min(mn,x);
}

signed main() {
	int a,b,c; cin>>a>>b>>c;
	mn=a+b+c;
	if(a%b==0) {
		f(a/b +c);
		f(a/b -c);
		f(a/b *c);
		if((a/b)%c==0) f((a/b)/c);
	}
	if((a+b)%c==0) f((a+b)/c);
	if((a-b)%c==0) f((a-b)/c);
	if((a*b)%c==0) f((a*b)/c);

	f(a+b+c);
	f(a+b-c);
	f((a+b)*c);
	f(a-b+c);
	f((a-b)*c);
	f(a-b-c);
	f(a*b+c);
	f(a*b-c);
	f(a*b*c);

	cout << mn << endl;
}
