/*
ID: neelbaja
TASK: beads
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int N;
    string b;
    fin >> N >> b;
    fout << N << " " << b[0%N] << b[1%N] << "\n";
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int l = i, r = (i+1), nb1 = 0, nb2 = 0;
        char lc = b[i], rc = b[(i+1)%N];
        set<int> vis;
        while((b[l] == lc || b[l] == 'w' || lc == 'w') && !vis.count(l)) {
            if(b[l] != 'w' && lc == 'w') lc = b[l];
            nb1++;
            vis.insert(l);
            l--;
            if(l == -1) l = N-1;
        }
        while((b[r] == rc || b[r] == 'w' || lc == 'w') && !vis.count(r)) {
            if(b[r] != 'w') rc = b[r];
            nb2++;
            vis.insert(r);
            r++;
            if(r == -1) r = N-1;
        }
        fout << i << (char)lc << char(rc) << " " << nb1 << " " << nb2 << "\n";
        ans = max(ans, nb1+nb2);
    }
    fout << ans << "\n";

    return 0;
} 
