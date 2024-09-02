/*
ID: neelbaja
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
using vvi = vector<vector<int>>;

vvi rot90(vvi m, int s) {
    vvi mnew;
    for(int i = 0; i < s; i++) {
        vector<int> row;
        for(int j = s-1; j >= 0; j--) {
            row.push_back(m[j][i]);
        }
        mnew.push_back(row);
    }
    return mnew;
}

vvi ref(vvi m, int s) {
    vvi mnew;
    for(int i = 0; i < s; i++) {
        vector<int> row;
        for(int j = s-1; j >= 0; j--) {
            row.push_back(m[i][j]);
        }
        mnew.push_back(row);
    }
    return mnew;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int N;
    cin >> N;
    vvi org, trn;
    for(int i = 0; i < N; i++) {
        vector<int> row;
        for(int j = 0; j < N; j++) {
            char k;
            cin >> k;
            row.push_back(k == '@');
        }
        org.push_back(row);
    }
    for(int i = 0; i < N; i++) {
        vector<int> row;
        for(int j = 0; j < N; j++) {
            char k;
            cin >> k;
            row.push_back(k == '@');
        }
        trn.push_back(row);
    }

    vvi otemp = org;

    for(int i = 0; i < 3; i++) {
        otemp = rot90(otemp, N);
        if(otemp == trn) {
            cout << i+1 << "\n";
            return 0;
        }
    }

    vvi oref = ref(org, N);
    if(oref == trn) {
        cout << "4\n";
        return 0;
    }

    otemp = oref;
    for(int i = 0; i < 3; i++) {
        otemp = rot90(otemp, N);
        if(otemp == trn) {
            cout << "5\n";
            return 0;
        }
    }

    if(org == trn) cout << "6\n";
    else cout << "7\n";

    return 0;
}
