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

#define DEV_ENV

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
    io("hoofball");
    int N;
    cin >> N;
    dbg << "N: " << N << endl;
    vector<int> cs;
    in(N, 0) {
        int cp;
        cin >> cp;
        cs.push_back(cp);
    }
    dbg << "In read" << endl;

    sort(cs.begin(), cs.end());
    // 0: cycle, 1: pass left, 2: pass right
    vector<int> cycles;
    map<int, int> c2p;

    in(N, 0) {
        if(i == 0) {
            c2p[cs[i]] = cs[i+1];
        } else if (i == N-1) {
            c2p[cs[i]] = c2p[cs[i-1]];
        } else if(c2p[cs[i]] - c2p[cs[i-1]] == c2p[cs[i+1]] - c2p[cs[i]]) {
            c2p[cs[i]] = c2p[cs[i-1]];
        } else if(c2p[cs[i]] - c2p[cs[i-1]] < c2p[cs[i+1]] - c2p[cs[i]]) {
            c2p[cs[i]] = c2p[cs[i-1]];
        } else {
            c2p[cs[i]] = c2p[cs[i+1]];
        }
    }

    dbg << "Filled c2p" << endl;

    int cyclesback = -1;
    in(N, 0) {
        int c = cs[i];
        if(c2p[c] == cs[i+1] && cyclesback == 1) {
            cycles.back() = 0;
        } else if(c2p[c] == cs[i+1]) {
            cycles.push_back(2);
        } else if (cyclesback == 2) {
            cycles.back() = 0;
        } else {
            cycles.push_back(1);
        }
        cyclesback = cycles.back();
    }

    dbg << "Filled cycles" << endl;

    int ans = 0;
    int pd = -1;
    int cyclessize = cycles.size();
    for(int i = 0; i < cyclessize; i++) {
        if(cycles[i] == 0 && pd == -1 && cycles[i+1] != 1) {
            ans++;
        } else if (cycles[i] == 0 && i == cyclessize-1 && cycles[i-1] != 2) {
            ans++;
        } else if (cycles[i] == 1 && pd != 1) {
            ans++;
        } else if (cycles[i] == 2 && pd != 2) {
            ans++;
        }
        pd = cycles[i];
    }

    cout << ans;
	return 0;
}

