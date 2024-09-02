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

void swap(pair<int, int> step, int *cows) {
    while(step.first < step.second) {
        int temp = cows[step.first];
        cows[step.first] = cows[step.second];
        cows[step.second] = temp;
        step.first++;
        step.second--;
    }
}

int main() {
    io("swap");
    int nc, ns;
    pair<int, int> step1, step2;
    int a,b,c,d;
    cin >> nc >> ns;
    cin >> a >> b >> c >> d;
    step1 = make_pair(a-1, b-1);
    step2 = make_pair(c-1, d-1);
    int cows[100];
    in(nc, 0) {
        cows[i] = i+1;
    }
    in(ns, 0) {
        swap(step1, cows);
        swap(step2, cows);
    }
    in(nc, 0) {
        cout << cows[i] << endl;
    }
	return 0;
}

