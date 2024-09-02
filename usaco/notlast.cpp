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

int main() {
    io("notlast");
    int nl;
    cin >> nl;
    int nc = 7;
    string cs[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> c2m;
    for(int i = 0; i < nc; i++) c2m[cs[i]] = 0;
    in(nl, 0) {
        string c;
        int m;
        cin >> c >> m;
        c2m[c] += m;
    }
    vector<pair<int, string> > ans;
    for(int i = 0; i < nc; i++) {
        ans.push_back(make_pair(c2m[cs[i]], cs[i]));
    }
    sort(ans.begin(), ans.end(), [](pair<int, string> a, pair<int, string> b) {
        return a.first < b.first;
    });
    int ansi = -1;
    in(nc, 1) {
        dbg << ans[i].first << " " << ans[i-1].first << " " << ans[i].second << endl;
        if(ans[i-1].first != ans[i].first) {
            ansi = i;
            break;
        }
    }
    dbg << ansi << endl;
    if(ansi == -1 || ans[ansi].first == ans[ansi+1].first) cout << "Tie";
    else cout << ans[ansi].second;
	return 0;
}

