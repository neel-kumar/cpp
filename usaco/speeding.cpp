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

pair<int, int> get_speeds(vector<pair<int, int> > s2sl, vector<pair<int, int> > s2bs, int d) {
    pair<int, int> sl_bs; 
    for(auto p : s2sl) {
        if(p.first >= d) {
            sl_bs.first = p.second;
            break;
        }
    }
    for(auto p : s2bs) {
        if(p.first >= d) {
            sl_bs.second = p.second;
            break;
        }
    }
    return sl_bs;
}

int main() {
    io("speeding");
    int rs, bs;
    cin >> rs >> bs;
    set<int> ip;
    vector<pair<int, int> > s2sl;
    vector<pair<int, int> > s2bs;
    int d = 0;
    in(rs, 0) {
        int x, y;
        cin >> x >> y;
        d += x;
        s2sl.push_back(make_pair(d, y));
        ip.insert(d);
    }
    d = 0;
    in(bs, 0) {
        int x, y;
        cin >> x >> y;
        d += x;
        s2bs.push_back(make_pair(d, y));
        ip.insert(d);
    }
    vector<int> sip(ip.begin(), ip.end());
    sort(sip.begin(), sip.end());
    int ans = 0;
    for(int d : sip) {
        pair<int, int> sl_bs = get_speeds(s2sl, s2bs, d);
        ans = max(ans, sl_bs.second - sl_bs.first);
    }
    cout << ans << endl;
	return 0;
}

