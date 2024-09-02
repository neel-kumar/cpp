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
    b = b+b;
    vector<pair<char, int>> pb;
    char rc = b[0];
    int rs = 1;
    for(int i = 1; i < N*2; i++) {
        if(rc == b[i]) rs++;
        else {
            pb.push_back(make_pair(rc, rs));
            rc = b[i];
            rs = 1;
        }
    }
    pb.push_back(make_pair(rc, rs));

    int pbs = pb.size(), ans = 0;
    // for(int i = 0; i < pbs; i++) cout << pb[i].first << pb[i].second << " ";
    // cout << "\n";
    if(pbs == 1) {
        cout << pb[0].second << "\n";
        return 0;
    }

    for(int i = 1; i < pbs-2; i++) {
        // cout << "Processing index: " << i << endl;
        char ci1 = pb[i].first;
        if(ci1 == 'w') ci1 = pb[i-1].first;
        // cout << "Left char is: " << ci1 << endl;
        int nb = 0;
        for(int j = i; j >= 0; j--) {
            if(pb[j].first != ci1 && pb[j].first != 'w') {
                break;
            } else
                nb += pb[j].second;
        }
        // cout << "Left string length: " << nb << endl;

        int nb2 = 0;
        char ci2 = pb[i+1].first;
        if(ci2 == 'w') ci2 = pb[i+2].first;
        // cout << "Right char is: " << ci2 << endl;
        for(int j = i+1; j < pbs; j++) {
            if(pb[j].first != ci2 && pb[j].first != 'w') {
                break;
            } else
                nb2 += pb[j].second;
        }
        // cout << "Right string length: " << nb2 << endl;

        ans = max(ans, nb+nb2);
    }
    fout << ans << "\n";

    return 0;
}
