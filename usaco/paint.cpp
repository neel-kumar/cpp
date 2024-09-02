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
    io("paint");
    int fj1, fj2, b1, b2;
    cin >> fj1 >> fj2 >> b1 >> b2;
    if(fj1 <= b1 && fj2 >= b2) {
        cout << fj2-fj1;
    } else if (b1 <= fj1 && b2 >= fj2) {
        cout << b2 - b1;
    } else if (fj1 <= b1 && fj2 >= b1 && fj2 <= b2) {
        cout << b2 - fj1;
    } else if (b1 <= fj1 && b2 >= fj1 && b2 <= fj2) {
        cout << fj2 - b1;
    } else {
        cout << (fj2-fj1) + (b2-b1);
    }
	return 0;
}

