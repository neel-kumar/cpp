#include <bits/stdc++.h>
using namespace std;

int n,p;

void reprem(string &s) {
	string t="";
	char c=' ';
	for(int i=0;i<n;i++) {
		if(s[i]!=c) {
			c=s[i];
			t+=s[i];
		}
	}
	s=t;
}

vector<pair<int,int>> f(string s1,string s2) {
	// clean back
	while(s1.size() && s1[0] == '1') s1=s1.substr(1);
	while(s2.size() && s2[0] == '2') s2=s2.substr(1);

	vector<pair<int,int>> ans;
	// 1st
	int one=(s2.size()==0 || s2[s2.size()-1]=='2')?3:2, two=one==2?3:2;
	cout << one << ' ' << two << endl;
	while(s1.size()>1) {
		if(s1[s1.size()-1] == '1')
			ans.push_back({1,one});
		else
			ans.push_back({1,two});
		s1=s1.substr(0,s1.size()-1);
	}

	if(two==3) {
		ans.push_back({1,3});
		s1="";
	}

	one=s1.size()==0?1:3,two=one==1?3:1;
	cout << one << ' ' << two << endl;
	while(s2.size()>0) {
		if(s2[s2.size()-1] == '1')
			ans.push_back({2,one});
		else
			ans.push_back({2,two});
		s2=s2.substr(0,s2.size()-1);
	}
	ans.push_back({two,2});

	if(s1.size()!=0) {
		ans.push_back({3,1});
	}
	return ans;
}


void solve() {
	string s1,s2;
	cin>>n>>p>>s1>>s2;
	reprem(s1);reprem(s2);

	vector<pair<int,int>> ans = f(s1,s2), ans2=f(s2,s1);
	/* if(ans2.size()<ans.size()) ans=ans2; */
	cout << ans.size() << endl;
	if(p>1)
		for(pair<int,int> i : ans)
			cout << i.first << ' ' << i.second << endl;
	ans=ans2;
	cout << ans.size() << endl;
	if(p>1)
		for(pair<int,int> i : ans)
			cout << i.first << ' ' << i.second << endl;
}

signed main() {
	int t;cin>>t;
	while(t--) solve();
}
