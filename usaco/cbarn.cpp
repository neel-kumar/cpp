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
#include <climits>

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
    io("cbarn");
    int N;
    cin >> N;
    int b[N];
    in(N, 0) {
        int x;
        cin >> x;
        b[i] = x;
    }
    int least = INT_MAX;
    in(N, 0) {
        int d = 0;
        int n = 0;
        for(int j = i; j < N; j++) {
            d += n * b[j];
            n++;
        }
        for(int j = 0; j < i; j++) {
            d += n * b[j];
            n++;
        }
        least = min(d, least);
    }
    cout << least;
	return 0;
}

