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
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define in(N, ii) for(int i = ii; i < N; i++)

// #define DEV_ENV

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

char cows[1001][1001];

vector<pair<int, int> >& create_trav(int x, int y, vector<pair<int, int> >& ans) {
    if(cows[x][y] != 0) ans.push_back(make_pair(x, y));
    if(y < 1000 && cows[x][y+1] != 0) ans.push_back(make_pair(x, y+1));
    if(y > 0 && cows[x][y-1] != 0) ans.push_back(make_pair(x, y-1));
    if(x < 1000 && cows[x+1][y] != 0) ans.push_back(make_pair(x+1, y));
    if(x > 0 && cows[x-1][y] != 0) ans.push_back(make_pair(x-1, y));
    return ans;
}

int main() {
#ifdef DEV_ENV
    freopen("cc.in", "r", stdin);
#endif
    int nc;
    cin >> nc;

    char cc[1001][1001];
    for(int i = 0; i < 1001; i++) for(int j = 0; j < 1001; j++) { cows[i][j] = 0; cc[i][j] = 0; }

    int totalcc = 0;

    in(nc, 0) {
        int x, y;
        cin >> x >> y;
        cows[x][y] = 1;
        dbg << i+1 << " " << x << " " << y << endl;

        vector<pair<int, int> > ans;
        for(auto & c : create_trav(x, y, ans)) {
            int na = 0;

            if(c.second > 0 && cows[c.first][c.second-1] != 0) na++;
            if(c.second < 1000 && cows[c.first][c.second+1] != 0) na++;
            if(c.first > 0 && cows[c.first-1][c.second] != 0) na++;
            if(c.first < 1000 && cows[c.first+1][c.second] != 0) na++;

            if(cc[c.first][c.second] == 1) {
                --totalcc;
                cc[c.first][c.second] = 0;
            }

            if(na == 3) {
                ++totalcc;
                cc[c.first][c.second] = 1;
            }
        }

        cout << totalcc << endl;
    }

	return 0;
}

