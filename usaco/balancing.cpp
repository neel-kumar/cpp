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

bool sortby1st(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.first < b.first);
}

int max_cow(vector<pair<int, int> >& c, int x, int y) {
    dbg << "max_cow " << x << " " << y << endl;
    int q[4];

    for(int a = 0; a < 4; a++) q[a] = 0;

    for(const pair<int, int>& cow : c) {
        if(cow.first > x && cow.second > y) q[0]++;
        if(cow.first < x && cow.second > y) q[1]++;
        if(cow.first < x && cow.second < y) q[2]++;
        if(cow.first > x && cow.second < y) q[3]++;
    }

    int max = 0;
    dbg << "Cows in 4 quadrants: " << q[0] << " " << q[1] << " " << q[2] << " " << q[3] << endl;
    for(int a = 0; a < 4; a++) if(q[a] > max) max = q[a];

    return max;
}

int main() {
    io("balancing");
    int N, B;
    cin >> N >> B;
    vector<pair<int, int> > c;
    in(N, 0) {
        int a, b;
        cin >> a >> b;
        c.push_back(make_pair(a, b));
        // c[i].first = a;
        // c[i].second = b;
    }
    sort(c.begin(), c.end(), sortby1st);

    int ans = INT32_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-1; j++) {
            int cur_max = max_cow(c, c[i].first+1, c[j].second+1);
            dbg << cur_max << endl;
            if(cur_max < ans) ans = cur_max;
        }
    }
    cout << ans << endl;
	return 0;
}

