#include <bits/stdc++.h>
#include <cstdio>
#include <type_traits>
#include <chrono>

using namespace std;
using ld = long double; using ll = long long;

int t, n, m;
vector<int> dsu(100003, 0), mpty(100003, 0);
vector<int> finans;

void dsu_reset() {
    for(int i = 0; i <= n; i++) {
        dsu[i] = i;
    }
}

int dsu_leader(int a) {
    if(a == dsu[a]) return a;
    else return dsu[a] = dsu_leader(dsu[a]);
}

void dsu_merge(int a, int b) {
    dsu[dsu_leader(b)] = dsu[dsu_leader(a)];
}

vector<pair<int, int>> merge_lists(vector<int> l1, vector<int> l2) {
    vector<pair<int, int>> ret;
    int i = 0, j = 0;
    while(i < l1.size() || j < l2.size()) {
        if(i < l1.size() && j < l2.size()) {
            if(l1[i] > l2[j]) {
                ret.push_back(make_pair(l2[j], 1));
                j++;
            } else {
                ret.push_back(make_pair(l1[i], 0));
                i++;
            }
        } else if(j < l2.size()) {
            ret.push_back(make_pair(l2[j], 1));
            j++;
        } else {
            ret.push_back(make_pair(l1[i], 0));
            i++;
        }
    }

    return ret;
}

int min_scc(int a, int b) {
    if(a == b) return 0;
    vector<int> ascc, bscc;
    for(int i = 1; i <= n; i++) {
        if(dsu_leader(i) == a) ascc.push_back(i);
        else if(dsu_leader(i) == b) bscc.push_back(i);
    }

    vector<pair<int, int>> mergedscc = merge_lists(ascc, bscc);
    int ret = INT32_MAX;
    for(int i = 0; i < mergedscc.size()-1; i++) {
        if(mergedscc[i].second != mergedscc[i+1].second) {
            int diff = abs(mergedscc[i].first - mergedscc[i+1].first);
            ret = min(ret, diff * diff);
        }
    }

    return ret;
}

int min_scc(int a, int b, vector<vector<int>>& l2vs) {
    // cout << "min_scc leaders " << a << ", " << b << endl;
    if(a == b) return 0;
    // cout << "Leaders are not same" << endl;

    vector<int>& ascc = l2vs[a], bscc = l2vs[b];

    int i = 0, as = ascc.size();
    int j = 0, bs = bscc.size();

    // cout << "as = " << as << " bs = " << bs << endl;

    int prev = 0;
    bool preva = true;
    if(ascc[0] < bscc[0]) {
        prev = ascc[0];
        preva = true;
    } else {
        prev = bscc[0];
        preva = false;
    }

    int ret = INT32_MAX;
    while(i < as && j < bs) {
        // cout << "ascc[i] " << ascc[i] << " bscc[j] " << bscc[j] << endl;
        if(ascc[i] < bscc[j]) {
            if(!preva) {
                // cout << "Checking preva(" << preva << ") " << prev << ", " << ascc[i] << endl;
                ret = min(ret, (prev - ascc[i]) * (prev - ascc[i]));
            }
            preva = true;
            prev = ascc[i];
            i++;
        } else {
            if(preva) {
                // cout << "Checking preva(" << preva << ") " << prev << ", " << bscc[j] << endl;
                ret = min(ret, (prev - bscc[j]) * (prev - bscc[j]));
            }
            preva = false;
            prev = ascc[j];
            j++;
        }
    }

    if(i < as) {
        if(!preva) {
            // cout << "Outside: checking preva(" << preva << ") " << prev << ", " << ascc[i] << endl;
            ret = min(ret, (prev - ascc[i]) * (prev - ascc[i]));
        }
    }

    if(j < bs) {
        if(preva) {
            // cout << "Outside: checking preva(" << preva << ") " << prev << ", " << bscc[j] << endl;
            ret = min(ret, (prev - bscc[j]) * (prev - bscc[j]));
        }
    }

    // cout << "min_scc leaders " << a << ", " << b << " = " << ret << endl;

    return ret;
}

int solve() {
    vector<vector<int>> l2vs(n + 1);
    for(int i = 1; i <= n; i++) {
        l2vs[dsu_leader(i)].push_back(i);
    }

    vector<int> leaders;
    for(int i = 1; i <= n; i++) {
        if(dsu[i] == i)
            leaders.push_back(i);
    }

    int sl = dsu_leader(1), dl = dsu_leader(n);
    int ret = min_scc(sl, dl, l2vs);

    for(int i : leaders) {
        ret = min(ret, min_scc(sl, i, l2vs) + min_scc(i, dl, l2vs));
    }
    return ret;
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        dsu_reset();
//        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < m; j++) {
            int a, b; cin >> a >> b;
            dsu_merge(a, b);
        }
//        auto finish = std::chrono::high_resolution_clock::now();
//        std::cout <<"dsu_merge " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << " ms\n";
        finans.push_back(solve());
//        auto finish2 = std::chrono::high_resolution_clock::now();
//        std::cout <<"solve " << std::chrono::duration_cast<std::chrono::milliseconds>(finish2-finish).count() << " ms\n";
    }

    for(int i : finans) printf("%d\n", i);

    return 0;
}
