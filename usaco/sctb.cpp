#include <iostream>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <set>

using namespace std;

int solve(int N, int M, map<int, vector<int>> p) {
    vector<vector<int>> g;
    set<int> v;
    for(int i = 1; i <= N; i++) {


int main() {
    freopen("sctb.in", "r", stdin);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        map<int, vector<int>> p;
        for(int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            p[x] = y;
            p[y] = x;
        }
        cout << solve(N, M, p) << endl;
    }

    return 0;
}
