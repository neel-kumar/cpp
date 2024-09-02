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

int maxn(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    io("hps");
    int N;
    cin >> N;
    vector<int> fj;
    in(N, 0) {
        char x;
        cin >> x;
        dbg << x << endl;
        if(x == 'H') fj.push_back(0);
        else if(x == 'S') fj.push_back(1);
        else fj.push_back(2);
    }

    vector<tuple<int, int, int>> fjps;
    tuple<int, int, int> sum = make_tuple(0, 0, 0);
    fjps.push_back(sum);
    for(int i : fj) {
        dbg << i << endl;
        if(i == 0) {
            get<0>(sum)++;
            //dbg << 0 << endl;
        } else if(i == 1) {
            get<1>(sum)++;
            //dbg << 1 << endl;
        } else {
            get<2>(sum)++;
            //dbg << 2 << endl;
        }
        fjps.push_back(sum);
    }

    int maxwins = 0;
    in(N, 0) {
        dbg << i << " " << maxn(get<0>(fjps[i+1]), get<1>(fjps[i+1]), get<2>(fjps[i+1])) << " " << maxn(get<0>(fjps[N]) - get<0>(fjps[i+1]), get<1>(fjps[N]) - get<1>(fjps[i+1]), get<2>(fjps[N]) - get<2>(fjps[i+1])) << endl;
        int wins = maxn(get<0>(fjps[i+1]), get<1>(fjps[i+1]), get<2>(fjps[i+1])) + maxn(get<0>(fjps[N]) - get<0>(fjps[i+1]), get<1>(fjps[N]) - get<1>(fjps[i+1]), get<2>(fjps[N]) - get<2>(fjps[i+1]));
        maxwins = max(wins, maxwins);
    }

    cout << maxwins;

	return 0;
}

