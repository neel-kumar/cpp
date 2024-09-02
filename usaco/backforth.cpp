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

struct tanks {
    map<int, int>& t1;
    map<int, int>& t2;

    set<int> readings1;

    tanks(map<int, int>& tmp1, map<int, int>& tmp2): t1(tmp1), t2(tmp2) {}

    void barn(const map<int, int>& my, const map<int, int>& other, const int n, const int mytank, const int othertank) {
        if(n > 0) {
            for(const auto& pair: my) {
                map<int, int> myc(my);
                map<int, int> otherc(other);

                // Remove the bucket from my buckets
                if(pair.second == 1) {
                    myc.erase(pair.first);
                } else {
                    myc[pair.first]--;
                }

                // Add the bucket in other buckets
                if(otherc.count(pair.first) > 0) {
                   otherc[pair.first]++;
                } else {
                   otherc[pair.first] = 1;
                }

                barn(otherc, myc, n - 1, othertank + pair.first, mytank - pair.first);
            }
        } else {
            //cout << "Tank: " << mytank << endl;
            readings1.insert(mytank);
        }
    }

    int get_readings1_after(int n)
    {
        map<int, int> b1(t1);
        map<int, int> b2(t2);
        barn(b1, b2, n, 1000, 1000);
        return readings1.size();
    }
};

int main() {
    io("backforth");
    map<int, int> t1, t2;

    in(10, 0) {
        int x;
        cin >> x;
        if(t1.count(x) != 0) {
            t1[x]++;
        } else {
            t1[x] = 1;
        }
    }

    in(10, 0) {
        int x;
        cin >> x;
        if(t2.count(x) != 0) {
            t2[x]++;
        } else {
            t2[x] = 1;
        }
    }

    //cout << "t1 " << endl; for(auto& p: t1) cout << p.first << ":" << p.second << endl;
    //cout << "t2 " << endl; for(auto& p: t2) cout << p.first << ":" << p.second << endl;

    tanks t(t1, t2);
    cout << t.get_readings1_after(4) << endl;
	return 0;
}
