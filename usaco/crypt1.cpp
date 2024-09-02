/*
ID: n27k
TASK: crypt1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

vector<array<int, 5>> combos;
set<int> ds;

void gencombos(int level, array<int, 5> combo) {
    if(level == 5) combos.push_back(combo);
    else {
        for(int i : ds) {
            array<int, 5> tcombo = combo;
            tcombo[level] = i;
            gencombos(level+1, tcombo);
        }
    }
}

bool validcrypt(int x, int ts) {
    int s = 0;
    while(x > 0) {
        if(ds.count(x%10) == 0) return false;
        x /= 10;
        s++;
    }
    return s==ts;
}

int main() {
    ifstream fin("crypt1.in");
    //ifstream tin(".txt");
    ofstream fout("crypt1.out");

    int N;
    fin >> N;
    for(int i = 0; i < N; i++) {
        int d;
        fin >> d;
        ds.insert(d);
    }

    array<int, 5> a;
    gencombos(0, a);

    int ans = 0;
    for(array<int, 5> crypt : combos) {
        //cout << crypt[0] << " " << crypt[1] << " " << crypt[2] << " " << crypt[3] << " " << crypt[4] << "\n";
        int a = crypt[0]*100 + crypt[1]*10 + crypt[2], b = crypt[3]*10 + crypt[4], pars1 = a*crypt[4], pars2 = a*crypt[3], fn = a*b;
        if(validcrypt(pars1, 3) && validcrypt(pars2, 3) && validcrypt(fn, 4)) ans++;
    }

    fout << ans << "\n";

    return 0;
}
