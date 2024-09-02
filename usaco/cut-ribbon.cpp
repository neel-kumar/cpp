#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int n, a, b, c;
int m = 0;
set<int> ps;

void dfs(int l, int rl) {
    cout << l << " " << rl << "\n";
    cout << ps.size();
    if(rl == 0) {
        m = max(m, l);
    } else if(l > 0) {
        for(auto i : ps) {
            dfs(l+1, rl-i);
            cout << l+1 << " " << rl-i << "\n";
        }
    }
}

int main() {
    cin >> n >> a >> b >> c;
    ps.insert(a);
    ps.insert(b);
    ps.insert(c);
    cout << ps.size();
    dfs(0, n);
    cout << m;

    return 0;
}
