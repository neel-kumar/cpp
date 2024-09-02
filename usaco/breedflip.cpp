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
    io("breedflip");
    string target, cur;
    int len;
    cin >> len >> target >> cur;
    dbg << len << " " << target << " " << cur << endl;
    int nsteps = 0;
    while(cur != target) {
        int lm = -1;
        int rm = -1;
        in(len, 0) {
            if(cur[i] != target[i] && lm == -1) lm = i;
            if(cur[i] != target[i]) rm = i;
            //dbg << len << " " << i << " " << cur[i] << " " << target[i] << " " << lm << " " << rm << endl;
        }
        dbg << target << " " << cur << " " << lm << " " << rm << endl;
        in(rm+1, lm) {
            if(cur[i] == 'G') cur[i] = 'H';
            else cur[i] = 'G';
        }
        nsteps++;
    }
    cout << nsteps;

	return 0;
}

