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

int main() {
#ifdef DEV_ENV
    freopen("lp.in", "r", stdin);
#endif
    int N;
    cin >> N;
    string l;
    cin >> l;
    int ans = 0;
    int cng = 0, cnh = 0;
    in(N, 0) {
        if(l[i] == 'G') cng++;
        else cnh++;
    }
    if(cng == 1 || cnh == 1) ans++;
    for(int i = 0; i < N; i++) {
        int tng = cng, tnh = cnh;
        for(int j = N-1; j >= i+2; j--) {
            if(tng == 1 || tnh == 1) ans++;
            if(l[j] == 'G') tng--;
            else tnh--;
            dbg << i << " " << j << " " << tng << " " << tnh << endl;
        }
        if(l[i] == 'G') cng--;
        else cnh--;
    }

    cout << ans;
	return 0;
}

