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
    io("mowing");
    map<pair<int, int>, int> c2lt;
    int S;
    cin >> S;
    int ans = INT32_MAX;
    int ct = 0;
    pair<int, int> cc = make_pair(0, 0);
    c2lt[cc] = 0;
    dbg << S << endl;
    in(S, 0) {
        char d;
        int s;
        cin >> d >> s;
        dbg << "input " << d << " " << s << endl;
        for(int j = 1; j <= s; j++) {
            ct++;
            if(d == 'N') {
                cc.second++;
                if(c2lt.count(cc) != 0) {
                    ans = min(ct - c2lt[cc], ans);
                }
                c2lt[cc] = ct;
            } else if (d == 'S') {
                cc.second--;
                if(c2lt.count(cc) != 0) {
                    ans = min(ct - c2lt[cc], ans);
                }
                c2lt[cc] = ct;
            } else if (d == 'E') {
                cc.first++;
                if(c2lt.count(cc) != 0) {
                    ans = min(ct - c2lt[cc], ans);
                }
                c2lt[cc] = ct;
            } else {
                cc.first--;
                if(c2lt.count(cc) != 0) {
                    ans = min(ct - c2lt[cc], ans);
                }
                c2lt[cc] = ct;
            }
            dbg << "time " << ct << " coords " << cc.first << " " << cc.second << " ans " << ans << endl;
        }
    }
    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
	return 0;
}

