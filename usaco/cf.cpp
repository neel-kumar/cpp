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

int c2i['Z'];
int d2t[4][4];

bool iscw(string d) {
    int ans = 0;
    int dsize = d.size();
    for(int i = 0; i < dsize; i++) {
        ans += d2t[c2i[d[i-1]]][c2i[d[i]]];
    }
    if(ans > 0) return true;
    else return false;
}

int main() {
#ifdef DEV_ENV
    freopen("cf.in", "r", stdin);
#endif

    c2i['N'] = 0;
    c2i['E'] = 1;
    c2i['S'] = 2;
    c2i['W'] = 3;

    for(int i  = 0; i < 4; i++) for(int j  = 0; j < 4; j++) d2t[i][j] = 0;
    d2t[0][1] = 1;
    d2t[1][2] = 1;
    d2t[2][3] = 1;
    d2t[3][0] = 1;
    d2t[0][3] = -1;
    d2t[3][2] = -1;
    d2t[2][1] = -1;
    d2t[1][0] = -1;
    
    int np;
    cin >> np;
    
    in(np, 0) {
        string d;
        cin >> d;
        if(iscw(d)) cout << "CW" << endl;
        else cout << "CCW" << endl;
    }

    return 0;
}
