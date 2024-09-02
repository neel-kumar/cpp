#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int x, y, k, m, ans = 2000000000;
bool memo[200][200][200];

void solve(int pail1, int pail2, int steps) { if (memo[pail1][pail2][steps]) return; memo[pail1][pail2][steps] = true;

    ans = min(ans, abs(m-pail1-pail2));
    if (steps == k) return;

    // all recursions
    solve(x, pail2, steps+1);
    solve(pail1, y, steps+1);
    solve(0, pail2, steps+1);
    solve(pail1, 0, steps+1);
    int left1 = x-pail1, left2 = y-pail2;
    if(pail1 > left2)
        solve(pail1-left2, y, steps+1);
    else
        solve(0, pail2+pail1, steps+1);
    if(pail2 > left1)
        solve(x, pail2-left1, steps+1);
    else
        solve(pail2+pail1, 0, steps+1);
}

int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> x >> y >> k >> m;
    solve(0, 0, 0);
    fout << ans << endl;
}
