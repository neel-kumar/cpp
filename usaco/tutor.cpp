/*
#include <iostream>
#include <cmath>
using namespace std;

int memo[1000][1000], n, k, p[1001], w[1001];

int solve(int weight, int item) {
  if (weight == 0 || item == n) return 0;
  if (memo[weight][item] != 0) return memo[weight][item];
  if (w[item] > weight) return memo[weight][item] = solve(weight, item + 1);
  return memo[weight][item] = max(solve(weight, item + 1),
                                  solve(weight - w[item], item + 1) + p[item]);
}

int solve(int weight, int item, int v) {
  if(weight < 0 || item >= n) return 0;
  if(memo[weight][item] != 0) return memo[weight][item];
  if(weight == 0) {
    return memo[weight][item] = v;
  }

  return memo[weight][item] = max(v, max(solve(weight, item+1, v), solve(weight-w[item], item+1, v+p[item])));
}

#include <iostream>
#include <set>
using namespace std;

int memo[1000][1000], len, n, coords[1002];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    p[i] = a;
    w[i] = b;
  }
  cin >> k;
  cout << solve(k, 0, 0);
}
*/








/*
#include <iostream>
#include <set>
using namespace std;

int memo[1000][1000], len, n, coords[1002];

Cutting Sticks
n cuts must be made on a stick.
The cut coordinates (places to cut the stick) are given.
The cost of a cut is the length of the stick to be cut.
The objective is to cut the stick in a certain order so that the cost is minimized.

int solve(int l, int r) {
  if (l + 1 == r) return 0;
  if (memo[l][r] != -1) return memo[l][r];

  int minCost = 2000000000;
  int currCost = coords[r] - coords[l];
  for (int i = l + 1; i < r; i++)
    minCost = min(minCost, solve(l, i) + solve(i, r) + currCost);
  return memo[l][r] = minCost;
}

int main() {
  cin >> len >> n;
  coords[0] = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    coords[i + 1] = x;
  }
  coords[n + 1] = len;

  memset(memo, -1, sizeof memo);
  cout << solve(0, n + 1);
}
*/













/*
Sample input:
10 10

input is n and k.
10+0+0+0+0+0+0+0+0+0 = 10
9+1+0+0+0+0+0+0+0+0 = 10
8+2+0+0+0+0+0+0+0+0 = 10
7+2+1+0+0+0+0+0+0+0 = 10
3+5+2+0+0+0+0+0+0+0 = 10

Sample output:
92378

#include <iostream>
#include <cstring>
using namespace std;

int memo[1000][1000];

int solve(int n, int k) {
  if(k == 1) return 1;
  int ret = 0;
  for(int i = 0; i <= n; i++) {
    ret += solve(n-i, k-1);
  }
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;
  memset(memo, -1, sizeof memo);
  cout << solve(n, k);
}
*/













/*
Obstacles Routes
These is a 2D plane, and its size is lengthX by lengthY.
You are at the top left corner (map[0][0]),
and your goal is to reach the bottom right corner (map[lengthX - 1][lengthY - 1]).
You can only move to the right or move downward.
However, there are some obstacles on some places (map[i][j]).
You cannot move to places with obstacles.
You must find all possible routest to the bottom right corner.
*/

/*
Sample input:
5 5
2
0 4
3 1

Sample output:
53


#include <iostream>
using namespace std;

int main() {
  int lengthX, lengthY, obstacles;
  cin >> lengthX >> lengthY >> obstacles;

  int map[1000][1000] = {};

  for (int i = 0; i < obstacles; i++) {
    int x, y;
    cin >> x >> y;
    map[x][y] = -1; // mark obstacles with -1
  }

  map[0][0] = 1;
  for (int i = 0; i < lengthX; i++)
    for (int j = 0; j < lengthY; j++) {
      if (map[i][j] == -1) {
        map[i][j] = 0;
        continue;
      }

      if (!i) map[i][j] = 1;
      if (!j) map[i][j] = 1;
      if (i && j) map[i][j] = map[i - 1][j] + map[i][j - 1];
  }

  cout << map[lengthX - 1][lengthY - 1];
}

*/









/*

#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi r, p;

int findSet(int i) {
  if (p[i] == i) return i;
  return p[i] = findSet(p[i]);
}

void connect(int a, int b) {
  if (r[a] > r[b]) p[b] = a;
  else if (r[a] < r[b]) p[a] = b;
  else p[a] = b, r[b]++;
}

int main() {
  int V, E; cin >> V >> E;
  vector <pair<int, ii> > edges; // vector of (weight, (vertex 1, vertex 2))
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(make_pair(w, ii(u, v)));
  }
  sort(edges.begin(), edges.end()); // To find Max spanning tree instead, just sort descendingly.

  r.assign(V, 0);
  p.assign(V, 0);
  for (int i = 1; i < V; i++) p[i] = i;

  int minCost = 0;
  for (int i = 0; i < edges.size(); i++) {
    pair<int, ii> front = edges[i];
    int a = findSet(front.second.first);
    int b = findSet(front.second.second);
    if (a != b) {
      minCost += front.first;
      connect(a, b);
    }
  }
  cout << minCost << endl;
}

*/

// Sample Input:
/*
5 7
0 1 4     0 2 4     0 3 6     0 4 6
1 2 2     2 3 8     3 4 9
*/

// Sample Output:
/*
18
*/

/*int main() {
  int V, E, adjMatrix[500][500];
  cin >> V >> E;

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      adjMatrix[i][j] = INF;
    adjMatrix[i][i] = 0;
  }

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adjMatrix[u][v] = w;
    //adjMatrix[v][u] = w;
  }

  for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);

  cout << "Below are min weights..." << endl;
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      adjMatrix[i][j] != INF ? cout << i << " -> " << j << " = " << adjMatrix[i][j] << endl: cout << i << " -> " << j << " cannot be reached" << endl;
}*/

// Sample Input:
/*
5 9
0 1 3   0 2 2   0 4 4   1 3 5   2 1 2
2 4 2   3 0 2   3 2 4   3 4 6
*/

// Sample Output:
/*
Below are shortest paths from a vertex to another:
0 -> 0:   0
0 -> 1:   0 1
0 -> 2:   0 2
0 -> 3:   0 1 3
0 -> 4:   0 4
1 -> 0:   1 3 0
1 -> 1:   1
1 -> 2:   1 3 2
1 -> 3:   1 3
1 -> 4:   1 3 4
2 -> 0:   2 1 3 0
2 -> 1:   2 1
2 -> 2:   2
2 -> 3:   2 1 3
2 -> 4:   2 4
3 -> 0:   3 0
3 -> 1:   3 0 1
3 -> 2:   3 2
3 -> 3:   3
3 -> 4:   3 4
4 -> 0:   cannot be reached.
4 -> 1:   cannot be reached.
4 -> 2:   cannot be reached.
4 -> 3:   cannot be reached.
4 -> 4:   4
*/

/*int main() {
  int V, E; cin >> V >> E;
  vector<vii> adjList(V, vii());
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back(ii(v, w));
  }

  int s = 2;
  vi dist(V, INF);
  dist[s] = 0;
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push(ii(0, s));

  while (!pq.empty()) {
    ii front = pq.top();
    pq.pop();
    int d = front.first;
    int u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < adjList[u].size(); j++) {
      int v = adjList[u][j].first;
      int w = adjList[u][j].second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(ii(dist[v], v));
      }
    }
  }

  cout << "Below are min weight..." << endl;
  for (int i = 0; i < V; i++)
    cout << s << " -> " << i << " = " << dist[i] << endl;
}*/

// Sample Input:
/*
5 7
2 1 2   2 3 7   2 0 6   1 3 3   1 4 6   3 4 5   0 4 1
*/

// Sample Output:
/*
Below are minimum weights required to travel from vertex 2 (source) to other vertices:
2 -> 0 = 6
2 -> 1 = 2
2 -> 2 = 0
2 -> 3 = 5
2 -> 4 = 7
*/

/*int s = 5;

int main() {
  int V, E; cin >> V >> E;
  vector<vi> adjList(V, vi());
  for (int i = 0; i < E; i++) {
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  vi dist(V, INF);
  dist[s] = 0;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int j = 0; j < adjList[u].size(); j++) {
      int v = adjList[u][j];
      if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  cout << "Below are min weight..." << endl;
  for (int i = 0; i < V; i++)
    cout << s << " -> " << i << " = " << dist[i] << endl;
}*/

// Sample Input:
/*
14 16
0 1   1  2   2  3   0  4   1  5   2  6    3  7    5  6
4 8   8  9   5 10   6 11   7 12   9 10   10 11   11 12
*/

// Sample Output:
/*
Below are minimum weights required to travel from vertex 5 (source) to other vertices:
5 -> 0 = 2
5 -> 1 = 1
5 -> 2 = 2
5 -> 3 = 3
5 -> 4 = 3
5 -> 5 = 0
5 -> 6 = 1
5 -> 7 = 4
5 -> 8 = 3
5 -> 9 = 2
5 -> 10 = 1
5 -> 11 = 2
5 -> 12 = 3
5 -> 13 = 1000000000
*/

/*vector<vi> adjList;
vector<bool> visited;

void dfs(int u) {
  cout << " " << u;
  visited[u] = 1;
  for (int j = 0; j < adjList[u].size(); j++) {
    int v = adjList[u][j];
    if (!visited[v]) dfs(v);
  }
}

int main() {
  int V, E;
  cin >> V >> E;

  adjList.assign(V, vi());
  for (int i = 0; i < E; i++) {
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  for (int i = 0; i < V; i++) {
    cout << i << " is connected to: ";
    for (int j = 0; j < adjList[i].size(); j++)
      cout << adjList[i][j] << " ";
    cout << endl;
  } cout << endl;

  cout << "Connected components and their numbers (undirected graph only):" << endl;
  visited.assign(V, 0);
  int count = 0;
  for (int s = 0; s < V; s++)
    if (!visited[s]) {
      cout << "Component " << ++count << ": ";
      dfs(s);
      cout << endl;
    }
  cout << "There are total " << count << " connected compoent(s)." << endl;
}*/

// Sample Input:
/*
10 7
0 1   1 2   2 9   4 5
6 7   7 8   8 6
*/

// Sample Output:
/*
0 is connected to: 1
1 is connected to: 0 2
2 is connected to: 1 9
3 is connected to:
4 is connected to: 5
5 is connected to: 4
6 is connected to: 7 8
7 is connected to: 6 8
8 is connected to: 7 6
9 is connected to: 2

Connected components and their numbers (undirected graph only):
Component 1:   0 1 2 9
Component 2:   3
Component 3:   4 5
Component 4:   6 7 8
There are total 4 connected component(s).
*/

/*int main() {
  int M, C, options;
  cin >> M >> C >> options;

  bool table[2][1000] = {};
  for (int j = 0; j < options; j++) {
    int price; cin >> price;
    if (M - price >= 0)
      table[0][M - price] = 1;
  }

  bool curr = 1;
  for (int i = 1; i < C; i++) {
    cin >> options;
    memset(table[curr], 0, sizeof(table[curr]));

    for (int j = 0; j < options; j++) {
      int price; cin >> price;

      for (int k = 0; k < M; k++)
        if (table[!curr][k] == 1 && k - price >= 0)
          table[curr][k - price] = 1;
    }
    curr = !curr;
  }

  int i;
  for (i = 0; i <= M; i++)
    if (table[!curr][i] == 1)
      break;
  i != M + 1 ? cout << M - i << endl : cout << "No solution" << endl;
}*/

/*
DFS (Depth first search)
BFS (Breadth first search)
Dijkstra
Warshall
MSP (Minimum Spanning Tree) - prims, krushkal
*/

  /*
          <-8-<-6-<---4----
  0 0 0 0 1 0 1 0 1 0 0 0 0
    <-5-<----5-----
  0 1 0 1 0 0 0 0 0 0 0 0 0
  <-3-<-1
  1 0 1 0 0 0 0 0 0 0 0 0 0
  */

// Wedding Shopping
// You have M amount of money. And there are C types of items.
// Given different options for each type of item, your must buy one option of each type of item.
// You cannot spend more than your M amount of money.
// However, you want to spend the maximum amount.
// What is thee maximum money you can use?
// If there is no solution since M is too small, print "No solution."

// Sample Input:
/*
12 3
3   6 4 8
2   5 10
4   1 5 3 5
*/

// Sample Output:
/*
12
*/

//HW????
// Angry cows: http://www.usaco.org/index.php?page=viewproblem2&cpid=594
// http://usaco.org/index.php?page=viewproblem2&cpid=190

/*#include <bits/stdc++.h>
using namespace std;

int main() {


  return 0;
}*/

/*#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ifstream fin("clumsy.in");
    //ifstream tin(".txt");
    ofstream fout("clumsy.out");

    string in;
    fin >> in;

    string res;
    for (int i = 0; i < in.size(); i++) {
      res += in[i];
      if (res.size() >= 2 && res.substr(res.size() - 2) == "()")
        res.resize(res.size() - 2);
    }

    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
      if (i % 2 == 0 && res[i] != '(') ans++;
      if (i % 2 == 1 && res[i] != ')') ans++;
    }
    fout << ans << endl;

    int l = 0, r = 0, ans = 0;
    string in; fin >> in;
    for(char i : in) {
        if(i == ')') l++;
        else r++;
        if(l > r) {
            l--;
            r++;
            ans++;
        }
    }
    if(l != r) {
        ans += (r-l)/2;
    }
    fout << ans << "\n";

    return 0;
}*/

/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=493
*/
/*
#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

long long pos[100001], speed[100001];

int main() {
  ifstream fin("cowjog.in");
  ofstream fout("cowjog.out");

  int n, t; fin >> n >> t;
  for (int i = 0; i < n; i++)
    fin >> pos[i] >> speed[i];

  int groups = n;
  for (int i = n - 1; i >= 0; i--) {
    pos[i] += speed[i] * t;
    if (i != n - 1 && pos[i] >= pos[i + 1])
      pos[i] = pos[i + 1], groups--;
  }
  fout << groups << endl;

  return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

/*
M+O+O

M 2
O 6
O 13

2+6+6 = 14
2+13+13 = 28
2+13+6 = 21
2+6+13 = 21
*/

typedef long long ll;
typedef vector<ll> vll;

int main() {
  int n;
  cin >> n;

  vector<vll> input(10, vll(10, 0));
  // B is 0, E is 1, S is 2, I is 3, G is 4, O is 5, M is 6.
  for (int i = 0; i < n; i++) {
    char ch;
    int num;
    cin >> ch >> num;
    if (ch == 'B') input[0][((num % 7) + 7) % 7]++;
    if (ch == 'E') input[1][((num % 7) + 7) % 7]++;
    if (ch == 'S') input[2][((num % 7) + 7) % 7]++;
    if (ch == 'I') input[3][((num % 7) + 7) % 7]++;
    if (ch == 'G') input[4][((num % 7) + 7) % 7]++;
    if (ch == 'O') input[5][((num % 7) + 7) % 7]++;
    if (ch == 'M') input[6][((num % 7) + 7) % 7]++;
  }

  ll count = 0;



  cout << count << endl;

  return 0;
}

/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=493
http://www.usaco.org/index.php?page=viewproblem2&cpid=549
*/
