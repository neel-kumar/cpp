#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int n, in[300][300];
vector<int> ans;

pair<int, int> min_max(vector<int> v, int a, int b) {
    int x = INT8_MIN, y = INT8_MAX;
    for(int i = a; i < b; i++) {
        x = max(x, v[i]);
        y = min(x, v[i]);
    }
    return make_pair(y, x);
}

bool is_valid(int x, int p) {
    for(int i = 0; i < p; i++) {
        pair<int, int> mm = min_max(ans, i, p);
        mm.first = min(mm.first, x);
        mm.second = max(mm.second, x);
        if(mm.second - mm.first != in[i][p])
            return false;
    }
    return true;
}

int f(int ma, int mi) {
    int prev = ans.size();
}

int main() {
    for(int i = 0; i < 300; i++)
        for(int j = 0; j < 300; j++)
            in[i][j] = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            int a; cin >> a;
            in[i][j+i] = a;
        }
    }

    ans.push_back(0);
    int m = f(0, 0);

    return 0;
}
