#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <list>
#include <string>
#include <tuple>
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
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<int> cs;
    in(N, 0) {
        int b;
        cin >> b;
        cs.push_back(b);
    }
    vector<tuple<int,int,int>> pscs;
    pscs.push_back(make_tuple(0, 0, 0));
    tuple<int,int,int> tot = make_tuple(0, 0, 0);
    in(N, 0) {
        if(cs[i] == 1) {
            get<0>(tot) += 1;
        } else if(cs[i] == 2) {
            get<1>(tot) += 1;
        } else {
            get<2>(tot) += 1;
        }
        pscs.push_back(tot); 
    }

    in(Q, 0) { 
        int p1, p2;
        cin >> p1 >> p2;
        cout << get<0>(pscs[p2]) - get<0>(pscs[p1-1]) << " " << get<1>(pscs[p2]) - get<1>(pscs[p1-1]) << " " << get<2>(pscs[p2]) - get<2>(pscs[p1-1]) << endl;
        dbg << get<0>(pscs[p2]) << " " << get<0>(pscs[p1-1]) << " " << get<1>(pscs[p2]) << " " <<  get<1>(pscs[p1-1]) << " " << get<2>(pscs[p2]) << " " <<  get<2>(pscs[p1-1]) << endl;
    }

	return 0;
}

