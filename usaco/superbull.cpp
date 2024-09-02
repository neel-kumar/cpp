#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi r, p;

int findSet(int i) { if (p[i] == i) return i; return p[i] = findSet(p[i]); }
void connect(int x, int y)
{
    if (r[x] > r[y]) p[y] = x;
    else if (r[x] < r[y]) p[x] = y;
    else p[x] = y, r[y]++;
}

int main() {
    ifstream fin("superbull.in");
    ofstream fout("superbull.out");
    int n; fin >> n;
    vi input(n);
    for (int i = 0; i < n; i++) fin >> input[i];

    vector< pair<int, ii> > edges(0); // (weight, (u, v))
                                      // make edges vector here (XOR = ^)
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            edges.push_back(make_pair(input[i]^input[j], make_pair(i, j)));

    // sort(edges.begin(), edges.end()); Minimum Spanning Tree
    sort(edges.rbegin(), edges.rend()); // Maximum Spanning Tree

    r.assign(n, 0);
    p.assign(n, 0); for (int i = 1; i < n; i++) p[i] = i;

    long long ans = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, ii> front = edges[i];
        int x = findSet(front.second.first);
        int y = findSet(front.second.second);
        if (x != y) ans += front.first, connect(x, y);
    }
    fout << ans << endl;

    return 0;
}
