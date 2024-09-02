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

int main() {
#ifdef DEV_ENV
    freopen("fs.in", "r", stdin);
#endif
    vector<int> cows;
    vector<int> cs;
    map<int, int> c2sc;
    int N;
    cin >> N;
    in(N, 0) {
        int h;
        cin >> h;
        cows.push_back(h);
        c2sc[h] = 0;
    }
    in(N, 0) {
        int h;
        cin >> h;
        cs.push_back(h);
        for(int i : cows) {
            if(i <= h) c2sc[i]++;
        }
    }

#ifdef NEEL
    sort(cows.begin(), cows.end(), greater<int>());
    long long ans = c2sc.at(cows.front());
    for(int i = 1; i < N; i++) {
        ans = ans * (c2sc.at(cows.at(i))-i);
    }
#else
    sort(cs.begin(), cs.end());
    map<int, int> cs2cc;
    for(int s: cs) {
        cs2cc[s] = 0;
    }

    for(auto & e: cs2cc) {
        for(int c: cows) {
            if(e.first >= c) {
                e.second++;
            }
        }
    }

    long long ans = cs2cc.at(cs.front());
    for(int i = 1; i < N; i++) {
        ans = ans * (cs2cc.at(cs.at(i)) - i);
    }
#endif

    cout << ans << endl;
	return 0;
}

