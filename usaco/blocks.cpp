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
    io("blocks");
    int nb;
    cin >> nb;
    string abcs = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> ans;
    for(char i : abcs) ans[i] = 0;
    in(nb, 0) {
        map<char, int> w1c;
        for(char c : abcs) w1c[c] = 0;
        map<char, int> w2c;
        for(char c : abcs) w2c[c] = 0;
        string w1, w2;
        cin >> w1 >> w2;
        for(char c : w1) w1c[c]++;
        for(char c : w2) w2c[c]++;
        for(char c : abcs) ans[c] += max(w1c[c], w2c[c]);
    }
    for(char c : abcs) cout << ans[c] << endl;
	return 0;
}

