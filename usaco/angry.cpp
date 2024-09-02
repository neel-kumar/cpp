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
    io("angry");
    int nb;
    cin >> nb;
    set<int> bales;
    in(nb, 0) {
        int bp;
        cin >> bp;
        bales.insert(bp);
    }
    int ans = 0;
    for(int r : bales) {
        set<int> ub(bales);
        ub.erase(r);
        int cbr = 1;
        set<int> eb, neb;
        eb.insert(r);
        while(eb.size() != 0) {
            for(int i : eb) {
                for(int j = i-cbr; j <= i+cbr; j++) {
                    if(ub.count(j) != 0) {
                        ub.erase(j);
                        neb.insert(j);
                    }
                }
            }
            cbr++;
            eb = neb;
            neb = {};
        }
        int tmp = ub.size();
        ans = max(nb-tmp, ans);
    }
    cout << ans;
	return 0;
}

