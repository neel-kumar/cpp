/*
ID: n27k
TASK: barn1
LANG: C++
*/

#include <bits/stdc++.h>
#include <utility>

using namespace std;

int main() {
    ifstream fin("barn1.in");
    //ifstream tin(".txt");
    ofstream fout("barn1.out");

    int M, S, C;
    fin >> M >> S >> C;

    vector<int> ocstalls;
    for(int i = 0; i < C; i++) {
        int j;
        fin >> j;
        ocstalls.push_back(j);
    }
    sort(ocstalls.begin(), ocstalls.end());

    vector<int> gaps;
    for(int i = 0; i < C-1; i++) {
        if(ocstalls[i+1]-ocstalls[i] > 1) {
            gaps.push_back(ocstalls[i+1]-ocstalls[i]-1);
        }
    }
    sort(gaps.begin(), gaps.end());
    int ans = ocstalls[C-1]-ocstalls[0]+1;
    int gs = gaps.size()-1;
    for(int i = 0; i < M-1; i++) {
        cout << ans << " ";
        if(gs < 0 || gs-i < 0) break;
        ans -= gaps[gs-i];
    }

    fout << ans << "\n";

    return 0;
}
