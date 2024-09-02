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
    freopen("emop.in", "r", stdin);
#endif
    int nci;
    cin >> nci;
    int e = 0, o = 0;
    in(nci, 0) {
        int ci;
        cin >> ci;
        if(ci%2 == 0) e++;
        else o++;
    }

    int gs = 0;
    bool pe = true;

#ifdef NEEL
    while(true) {
        if((e == 0 && o < 2) || (o == 0)) break;
        if(pe && e != 0) {
            e--;
        } else if(pe) {
            o -= 2;
        } else {
            o--;
        }
        pe = !pe;
        gs++;
    }

    if(o == 1) gs--;
#else

    while(true) {
        if(pe) {
            if(e > 0) {
                --e;
            } else if(o >= 2) {
                o -= 2;
            } else {
                if(o == 1) --gs;

                break;
            }
        } else {
            if(o > 0) {
                o--;
            } else {
                break;
            }
        }
        pe = !pe;
        gs++;
    }

#endif

    cout << gs;

    return 0;
}

