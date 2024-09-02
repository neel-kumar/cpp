#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        if(s.size() <= 10)
            cout << s << endl;
        else
            cout << s[0] << s.size()-2 << s[s.size()-1] << "\n";
    }

    return 0;
}
