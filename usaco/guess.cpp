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

int ans(set<string> c[100], int N) {
    int ma = 1;
    for(int i = N-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            int x = 0;
            for(string s : c[i]) {
                if(c[j].count(s) != 0) x++;
            }
            dbg << i << " " << to_string(c[i]) << j << " " << to_string(c[j]) << " " << x << endl;
            // if(x > ma) ma = x;
            ma = max(ma, x);
        }
    }
    return ma+1;
}

int main() {
	freopen("guess.in", "r", stdin);
#ifndef DEV_ENV
	freopen("guess.out", "w", stdout);
#endif

    int N;
    cin >> N;

    dbg << "No of animals: " << N << endl;

    set<string> c[100];

    in(N, 0) {
        string a;
        int K;
        cin >> a >> K;
        for(int j = 0; j < K; j++) {
            string ch;
            cin >> ch;
            c[i].insert(ch);
        }
        dbg << "No of traits of " << i << "th animal is " << c[i].size() << endl;
    }

    cout << ans(c, N) << endl;

	return 0;
}

