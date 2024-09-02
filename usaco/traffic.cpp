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

void none(int lr, int ur, int &fl, int &fu) {
    fl = std::max(lr, fl);
    fu = std::min(ur, fu);
}

void onr(int lr, int ur, int &fl, int &fu) {
    fl += lr;
    fu += ur;
}

void outr(int lr, int ur, int &fl, int &fu) {
    fl -= ur;
    fl = max(fl, 0);
    fu -= lr;
}

void inflow(tuple<int, int, int> *r, int N) {
    int fl = -1, fu = 1001;
    for(int i = N-1; i >= 0; i--) {
        int tr, lr, ur;
        tie(tr, lr, ur) = r[i];
        if(tr == 0) none(lr, ur, fl, fu);
        else if(tr == 1) outr(lr, ur, fl, fu);
        else onr(lr, ur, fl, fu);
    }
    cout << fl << " " << fu << endl; 
}

void outflow(tuple<int, int, int> *r, int N) {
    int fl = -1, fu = 1001;
    for(int i = 0; i < N; i++) {
        int tr, lr, ur;
        tie(tr, lr, ur) = r[i];
        if(tr == 0) none(lr, ur, fl, fu);
        else if(tr == 1) onr(lr, ur, fl, fu);
        else outr(lr, ur, fl, fu);
    }
    cout << fl << " " << fu << endl; 
}

int main() {
    freopen("traffic.in", "r", stdin);
#ifndef DEV_ENV
	freopen("traffic.out", "w", stdout);
#endif

    int N;
    cin >> N;
    tuple<int, int, int> r[100];
    in(N, 0) {
        string x;
        int l, u, xi;
        cin >> x >> l >> u;
        if(x == "none") xi = 0;
        else if(x == "on") xi = 1;
        else xi = 2;
        r[i] = make_tuple(xi, l, u);
    }

    inflow(r, N);
    outflow(r, N);
	return 0;
}

