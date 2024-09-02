// http://www.usaco.org/index.php?page=viewproblem2&cpid=513

#include <bits/stdc++.h>
#include <type_traits>

using namespace std;
using ld = long double;
using ll = long long;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
vector<vii> adjListB, adjListE;
vector<int> bes, el;
bool visitedB[100][10000], visitedE[100][10000];

void dfs_b(int f, int t) {
    if (visitedB[f][t]) return;
    visitedB[f][t] = true;

    if(f == n - 1) {
      bes.push_back(t);
      return;
    }

    for(ii i : adjListB[f]) {
        if (!visitedB[i.first][t+i.second])
          dfs_b(i.first, t+i.second);
    }
}

void dfs_e(int f, int t) {
    if (visitedE[f][t]) return;
    visitedE[f][t] = true;

    if(f == n - 1) {
      el.push_back(t);
      return;
    }

    for(ii i : adjListE[f]) {
        if (!visitedE[i.first][t+i.second])
          dfs_e(i.first, t+i.second);
      }
}

int main() {
    ifstream fin("meeting.in");
    //ifstream tin(".txt");
    ofstream fout("meeting.out");

    fin >> n >> m;
    adjListB.assign(n, vii());
    adjListE.assign(n, vii());
    for(int i = 0; i < m; i++) {
        int a, b, c, d; fin >> a >> b >> c >> d;
        a--, b--;
        adjListB[a].push_back(ii(b, c));
        adjListE[a].push_back(ii(b, d));
    }
    dfs_b(0, 0);
    dfs_e(0, 0);
    sort(bes.begin(), bes.end());
    sort(el.begin(), el.end());

    for (const int &i : bes)
      for (const int &j : el)
        if (i == j) {
          fout << i << endl;
          return 0;
        }
    fout << "IMPOSSIBLE\n";

    /*int i = 0, j = 0;
    while(i < min(bes.size(), el.size()) && j < min(bes.size(), el.size())) {
        if(i == j) {
            cout << bes[i] << "\n";
            return 0;
        }
        if(i < j) i++;
        else if(j < i) j++;
        else {
            i++;
            j++;
        }
    }
    cout << "IMPOSSIBLE\n";*/

    return 0;
}
