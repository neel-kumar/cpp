/*
ID: neelbaja
TASK: milk2
LANG: C++
*/

#include <bits/stdc++.h>
#include <utility>

using namespace std;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> fm;
    for(int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        fm.push_back(make_pair(s, -1));
        fm.push_back(make_pair(e, 1));
    }
    sort(fm.begin(), fm.end());
    int rs = 0, bt = fm[0].first, cc = fm[0].first, nof = 0, wf = 0;
    for(pair<int, int> i : fm) {
        //cout << bt << " " << cc << " " << cc-bt << "\n";
        wf = max(wf, cc-bt);
        if(rs == 0 && cc != i.first) {
            nof = max(nof, i.first-cc);
            bt = i.first;
        }
        rs += i.second;
        cc = i.first;
    }
    wf = max(wf, cc-bt);

    cout << wf << " " << nof << "\n";

    return 0;
}
