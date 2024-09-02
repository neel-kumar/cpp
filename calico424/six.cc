#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin>>s;
    if (s=="START") {
        cout<<"500500\n";
    } else if (s=="OBSERVE") {
        int input;
        cin>>input;
        int sg = input/1000, bs = input%1000;
        char c;
        cin>>c;
        if (c=='S') {
			bs++;
			sg--;
		}
        else if (c=='G') sg++;
        else if (c=='B') bs--;

        cout<< sg*1000+bs << '\n';
    } else {
        int input;
        cin>>input;
        int sg = input/1000, bs = input%1000;

		int a[3];
		a[0] = 0;
		a[1] = bs-500;
		a[2] = sg-500 + a[1];

		int x = 0;
		for(int i = 1; i < 3; i++) {
			if(a[x] < a[i]) x = i;
		}
		if(x == 0) cout << "B";
		else if(x == 1) cout << "S";
		else cout << "G";

		a[x] = INT_MIN;
		x = 0;
		for(int i = 1; i < 3; i++) {
			if(a[x] < a[i]) x = i;
		}
		if(x == 0) cout << "B";
		else if(x == 1) cout << "S";
		else cout << "G";

		a[x] = INT_MIN;
		x = 0;
		for(int i = 1; i < 3; i++) {
			if(a[x] < a[i]) x = i;
		}
		if(x == 0) cout << "B";
		else if(x == 1) cout << "S";
		else cout << "G";
		cout << endl;
    }

    return 0;
}
