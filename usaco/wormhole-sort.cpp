/*
ID: n27k
TASK: task
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int n, m;
vector<int> cows, widths;
map<int, vector<pair<int, int>>> whs;
map<int, int> swaps;
int dsu[1000000];

// dsu code
void initdsu(int size) {
    //assume dsu called dsu
    for(int i = 0; i < size; i++) {
        dsu[i] = i;
    }
}

int get_leader(int a) {
    if(dsu[a] == a) return a;
    else {
        dsu[a] = get_leader(dsu[a]);
        return dsu[a];
    }
}

void merge(int a, int b) {
    dsu[get_leader(a)] = dsu[get_leader(b)];
}
// dsu end

bool f(int x) {
    initdsu(1000000);
    for(auto i : whs) {
        for(auto j : i.second) {
            if(j.second >= x) {
                merge(i.first, j.first);
            }
        }
    }
    for(auto i : swaps) {
        if(get_leader(i.first) != get_leader(i.second)) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    fin >> n >> m;
    for(int i = 0; i < n; i++) {
        int cp; fin >> cp;
        cows.push_back(cp);
        if(cp != i+1) {
            swaps[i+1] = cp;
            swaps[cp] = i+1;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c; fin >> a >> b >> c;
        whs[a].push_back(make_pair(b, c));
        whs[b].push_back(make_pair(a, c));
        widths.push_back(c);
    }

    // Already sorted
    if(swaps.size() == 0) {
        fout << "-1\n";
        return 0;
    }

    sort(widths.begin(), widths.end());

    //binary search
    int l = 0, r = m-1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(f(widths[mid])) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    fout << widths[l-1] << "\n";
    return 0;
}
