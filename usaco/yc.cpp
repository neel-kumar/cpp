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
    freopen("yc.in", "r", stdin);
#endif
    string zs[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    map<string, int> z2y;
    in(12, 0) z2y[zs[i]] = i;

    map<string, pair<int, int> > c2yfb;
    c2yfb["Bessie"] = make_pair(0, 0);

    int N;
    cin >> N;

    in(N, 0) {
        string a, b, c, d, e, f, g, h; // a, d, e, h
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        if(z2y[e] >= c2yfb[h].second && d == "previous") {
            dbg << "> prev" << " " << c2yfb[h].second << " " << z2y[e] << endl;
            c2yfb[a] = make_pair((c2yfb[h].first - 12 - c2yfb[h].second + z2y[e]), z2y[e]);
        } else if(z2y[e] < c2yfb[h].second && d == "previous") {
            dbg << "< prev" << " " << c2yfb[h].second << " " << z2y[e] << endl;
            c2yfb[a] = make_pair((c2yfb[h].first - c2yfb[h].second + z2y[e]), z2y[e]);
        } else if(z2y[e] > c2yfb[h].second && d == "next") {
            dbg << "> next" <<  " " << c2yfb[h].second << " " << z2y[e] << endl;
            c2yfb[a] = make_pair((c2yfb[h].first - c2yfb[h].second + z2y[e]), z2y[e]);
        } else {
            dbg << "< next" << " " << c2yfb[h].second << " " << z2y[e] << endl;
            c2yfb[a] = make_pair((c2yfb[h].first + 12 - c2yfb[h].second + z2y[e]), z2y[e]);
        }
        dbg << a << " " << c2yfb[a].first << " " << c2yfb[a].second << endl;
    }

    // if(c2yfb["Elsie"].first < 0) cout << (c2yfb["Elsie"].first * -1);
    // else cout << (c2yfb["Elsie"].first);

    cout << abs(c2yfb["Elsie"].first) << endl;

	return 0;
}

