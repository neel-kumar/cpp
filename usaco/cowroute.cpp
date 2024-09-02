#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowroute.in");
    //ifstream tin(".txt");
    ofstream fout("cowroute.out");
    int a, b, n;
    fin >> a >> b >> n;
    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        int x, y; fin >> x >> y;
        bool startFound = false;
        for(int j = 0; j < y; j++) {
            int c; fin >> c;
            if(c == a)
                startFound = true;
            if(startFound && c == b) {
                ans = min(ans, x);
            }
        }
    }

    if(ans == 1e9) ans = -1;

    fout << ans << endl;

    return 0;
}
