#include <bits/stdc++.h>

using namespace std;

char g[15][15];
int c, r, ans;

void f(int x, int y) {
    if(x == r-1 && y == c-1) {
        ans++;
        return;
    }
    for(int i = x+1; i < r; i++)
        for(int j = y+1; j < c; j++)
            if(g[x][y] != g[i][j])
                f(i, j);
}

int main() {
    ifstream fin("hopscotch.in");
    //ifstream tin(".txt");
    ofstream fout("hopscotch.out");

    fin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            fin >> g[i][j];
        }
    }

    f(0, 0);
    fout << ans << endl;

    return 0;
}
