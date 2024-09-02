#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long long o, w, n;

int main() {
    ifstream fin("cow.in");
    //ifstream tin(".txt");
    ofstream fout("cow.out");

    ll n;
    string str;
    fin >> n >> str;

    ll c = 0, o = 0, w = 0;
    for (ll i = 0; i < n; i++) {
        if (str[i] == 'C') c++;
        if (str[i] == 'O') o+=c;
        if (str[i] == 'W') w+=o;
    }

    fout << w << endl;

    return 0;
}

/*    fin >> n;
    string s; fin >> s;
    long long ans = 0;
    bool stw = false;
    int wprev = 0;
    for(long long i = n-1; i >= 0; i--) {
        if(s[i] == 'W') {
            w++;
            stw = true;
            wprev++;
        } else if(s[i] == 'O' && stw) {
            o++;
            wprev = 0;
        } else {
            ans += (w-wprev)*o;
        }
    }
    fout << ans << endl;
}
*/
