/*
ID: neelbaja
TASK: friday
LANG: C++
*/

#include <bits/stdc++.h>
#include <cstdint>
#include <cstdlib>

using namespace std;

int main() {
    //freopen("beads.in", "r", stdin);
    //freopen("beads.out", "w", stdout);
    int N;
    string b;
    cin >> N >> b;

    vector<pair<char, int>> pb;
    b = b+b;
    char rc = b[0];
    int rs = 1;
    for(int i = 1; i < N; i++) {
        if(rc == b[i]) rs++;
        else {
            pb.push_back(make_pair(rc, rs));
            rc = b[i];
            rs = 1;
        }
    }
    pb.push_back(make_pair(rc, rs));
    if(pb.front().first == pb.back().first) {
        pb.front().second += pb.back().second;
        pb.pop_back();
    }
    int ans = pb.back().second+pb[0].second, pbs = pb.size();
    for(int i = 1; i < pbs-1; i++) {
        if(pb[i].first == 'w' && pb[i-1].first == pb[i+1].first) {
            pb[i-1].second += pb[i+1].second + pb[i].second;
            pb.erase(pb.begin()+i, pb.begin()+i+2);
            pbs--;
        }
    }

    cout << pbs << "\n";
    for(int i = 0; i < pbs; i++)
        cout << pb[i].first << pb[i].second << "\n";

    for(int i = 0; i < pbs-1; i++) {
        int nb = pb[i].second + pb[i+1].second;
        if(pb[i].first == 'w' && i != 0)
            nb += pb[i-1].second;
        if(pb[i+1].first == 'w' && i < pbs-1)
            nb += pb[i+2].second;
        ans = max(ans, nb);
        //cout << i << " " << ans << "\n";
    }

    cout << ans;
    return 0;
}

