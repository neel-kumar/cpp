#include <bits/stdc++.h>
using namespace std;

signed main() {
	string s;cin>>s;

	string c=" "; c+=s[0];
	int i;
	bool found=false;
	for(i=1;i<s.size();i++) {
		c=c[1]; c+=s[i];
		if(c=="AB") {
			found=true;
			i++;
			c=c[1]; c+=s[i];
			break;
		}
	}
	for(;i<s.size() && found;i++) {
		c=c[1]; c+=s[i];
		if(c=="BA") {
			cout << "YES\n";
			return 0;
		}
	}

	found=false;
	c=" "; c+=s[0];
	for(i=1;i<s.size();i++) {
		c=c[1]; c+=s[i];
		if(c=="BA") {
			found=true;
			i++;
			c=c[1]; c+=s[i];
			break;
		}
	}
	for(;i<s.size() && found;i++) {
		c=c[1]; c+=s[i];
		if(c=="AB") {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}
