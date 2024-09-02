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
    io("triangles");
    map<int, vector<int>> x2y;
    map<int, pair<int, int>> y2x;
    int nc;
    cin >> nc;
    dbg << "Number Pts " << nc << endl;
    // reading: x2y all points, y2x left and right most points
    in(nc, 0) {
        int x, y;
        cin >> x >> y;
        x2y[x].push_back(y);
        if(y2x.count(y) == 0) {
            y2x[y].first = x;
            y2x[y].second = x;
        } else {
            y2x[y].first = min(y2x[y].first, x);
            y2x[y].second = max(y2x[y].second, x);
        }
    }
    int ans = 0;
    dbg << "start ans " << ans << endl;
    //iterate over x values
    for(auto & i : x2y) {
        // sort all pts on that x and find mid pt between them
        sort(i.second.begin(), i.second.end());
        //int avg = (i.second[0] + i.second[i.second.size()-1])/2;
        dbg << "avg of " << i.first << " : " << i.second.front() << " , " << i.second.back() << endl;
        //find out max triangle for each pt and compare to max
        for(int j : i.second) {
            int x = max(i.first - y2x[j].first, y2x[j].second - i.first);
            int y = max(i.second.back() - j, j - i.second.front());
            /*if(j < avg) {
                x = i.second[i.second.size()] - j;
            } else {
                x = j - i.second[0];
            }
            */
            ans = max(ans, y*x);
            dbg << "new ans " << ans << endl;
        }
    }
    cout << ans;
	return 0;
}

