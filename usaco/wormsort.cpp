#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int N, M;
vector<int> co;
vector<vector<int>> wh;

bool mycomp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

bool iss(vector<int> cs) {
    int prev = 0;
    for(int i : cs) {
        if(i < prev) {
            return false;
        }
        prev = i;
    }
    return true;
}

void swap(vector<int>& v, int i, int j) {
    int t = v.at(j);
    v.at(j) = v.at(i);
    v.at(i) = t;
}

bool dfs(vector<int> cs, set<vector<int>> memo, int i, vector<int> prev) {
    if(cs == prev) {
        return false;
    }
    prev = cs;
    for(int j : cs) {
        cout << j << " ";
    }
    cout << wh.at(i).at(0) << " " << iss(cs) << " " << memo.count(cs) << endl;
    if(iss(cs)) {
        return true;
    } else if(memo.count(cs) == 0) {
        cout << "BEGIN DFS " << M-1 << " " << i << endl;
        memo.insert(cs);
        for(int j = M-1; j >= i; j--) {
            cout << "BEFORE tcs cs" << endl;
            vector<int> tcs;
            tcs = cs;
            cout << "BEFORE SWAP" << endl;
            swap(tcs, wh.at(i).at(1), wh.at(i).at(2));
            cout << "AFTER SWAP" << endl;
            if(dfs(tcs, memo, j, prev)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string f = "wormsort";
    freopen((f + ".in").c_str(), "r", stdin);
    //freopen((f + ".out").c_str(), "w", stdout);
    cin >> N >> M;
    int p = 0;
    bool s = true;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        co.push_back(x);
        if(x < p) {
            s = false;
        } else {
            p = x;
        }
    }
    if(s) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> a;
        a.push_back(z);
        a.push_back(x);
        a.push_back(y);
        wh.push_back(a);
    }
    sort(wh.begin(), wh.end(), mycomp);

    for(int i = M-1; i >= 0; i--) {
        set<vector<int>> memo;
        cout << "NEW " << wh.at(i).at(0) << " END" <<  endl;
        vector<int> prev;
        if(dfs(co, memo, i, prev)) {
            cout << wh.at(i).at(0);
            return 0;
        }
    }

	return 0;
}

