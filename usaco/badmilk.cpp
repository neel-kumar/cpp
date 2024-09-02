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

#define in(N, ii) for(int i = ii; i < N; i++)

//#define DEV_ENV

#ifdef DEV_ENV
#define dbg cout << "DEBUG: "
#else
#define dbg if(true) {} else cout
#endif

template<typename T>
string to_string(T begin, T end)
{
    stringstream ss;
    bool first = true;
    for(; begin != end; begin++)
    {
        if(!first) ss << ", ";
        first = false;
        ss << *begin;
    }

    return ss.str();
}

template<typename T>
string to_string(const vector<T>& v)
{
    return to_string(v.begin(), v.end());
}

template<typename T>
string to_string(const vector<T>* v)
{
    return to_string(v->begin(), v->end());
}

template<typename T>
string to_string(const set<T>& v)
{
    return to_string(v.begin(), v.end());
}

template<typename T>
string to_string(const set<T>* v)
{
    return to_string(v->begin(), v->end());
}

template<typename T>
string to_string(T *a, int size) {
    return to_string(vector<T>(a, a+size));
}

void io(string f) {
    freopen((f + ".in").c_str(), "r", stdin);
#ifndef DEV_ENV
    freopen((f + ".out").c_str(), "w", stdout);
#endif
}

vector<int> find_common(map<int, set<int>> &sm, vector<int> &s, int S) {
    vector<int> c;
    dbg << "find_common" << " " << sm[s[0]].size() << endl;
    for(int i : sm[s[0]]) {
        dbg << "Sick cow: " << i << endl;
        bool common = true;
        for(int j = 1; j < S; j++) {
           if(sm[s[j]].count(i) == 0) common = false;
        } 
        if(common) {
            c.push_back(i);
            dbg << "Common milk: " << i << endl;
        }
    }
    return c;
}

int main() {
    io("badmilk");
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    map<int, vector<pair<int, int>>> pdm;
    in(N, 0) {
        pdm[i+1] = {};
    }
    in(D, 0) {
        int p, m, t;
        cin >> p >> m >> t;
        pdm[p].push_back(make_pair(m, t));
    }
    map<int, int> s;
    vector<int> sp;
    in(S, 0) {
        int p, t;
        cin >> p >> t;
        s[p] = t;
        sp.push_back(p);
    }
    map<int, set<int>> sm;
    map<int, set<int>> um; 
    vector<int> uc;
    in(N+1, 1) {
        if(s.count(i) != 0) {
            for(auto p : pdm[i]) {
                if(p.second < s[i]) {
                    sm[i].insert(p.first);
                }
            }
        } else {
            uc.push_back(i);
            for(auto p : pdm[i]) {
                um[i].insert(p.first);
            }
        }
    }
    int ans = 0;
    vector<int> commons = find_common(sm, sp, S);
    dbg << commons.size() << " " << sm[1].size() << " " << pdm[1].size() << " " << sm[2].size() << " " << pdm[2].size() << endl;
    for(int i : commons) {
        int ps = 0;
        for(int j : uc) {
            dbg << "uc " << j << endl;
            if(um[j].count(i) != 0) ps++;
        }
        dbg << i << " " << ps << endl;
        ans = max(ans, ps);
    }

    cout << ans+S;
	return 0;
}

