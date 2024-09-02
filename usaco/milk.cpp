/*
ID: n27k
TASK: milk
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("milk.in");
    //ifstream tin(".txt");
    ofstream fout("milk.out");

    int N, M;
    fin >> N >> M;
    vector<pair<int, int>> fmrsp;
    for(int i = 0; i < M; i++) {
        int p, a;
        fin >> p >> a;
        fmrsp.push_back(make_pair(p, a));
    }
    sort(fmrsp.begin(), fmrsp.end());

    int i = 0, ans = 0;
    while(N > 0) {
        if(N >= fmrsp[i].second) {
            N -= fmrsp[i].second;
            ans += fmrsp[i].first * fmrsp[i].second;
        } else {
            ans += fmrsp[i].first*N;
            N=0;
        }
        i++;
    }

    fout << ans << "\n";

    return 0;
}
