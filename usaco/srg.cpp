#include <map>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int N;
int c2pg[501][501];
set<vector<int>> pg;

bool is_valid(const vector<int>& g) {
    for(int i = 1; i <= N; i++) {
        if(c2pg[i][g[i-1]] > c2pg[i][i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> g;
        for(int j = 0; j < N; j++) {
            int x;
            cin >> x;
            c2pg[i+1][x] = j;
            g.push_back(x);
        }
        pg.insert(g);
    }

    vector<vector<int>> valids;
    for(auto &i : pg) {
        if(is_valid(i)) {
            valids.push_back(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        int min_val = valids[0][i-1], min = c2pg[i][min_val];
        for(auto & j : valids) {
            if(c2pg[i][j[i-1]] < min) {
                min = c2pg[i][j[i-1]];
                min_val = j[i-1];
            }
        }
        cout << min_val << endl;
    }

    return 0;
}
