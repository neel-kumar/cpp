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

int art[10][10];
int c2r[10][6];

int main() {
    io("art");
    int N;
    cin >> N;
    dbg << "N " << N << endl;

    in(10, 0) {
        for(int j = 0; j < 6; j++) {
            c2r[i][j] = -1;
        }
    }

    vector<int> vc;
    set<int> pa;

    in(N, 0) {
        string row;
        cin >> row;
        for(int j = 0; j < N; j++) {
            int ci = row[j] - '0';
            if(pa.count(ci) == 0 && ci != 0) {
                vc.push_back(ci);
                pa.insert(ci);
            }
            art[i][j] = ci;
        }
    }

    in(N, 0) {
        set<int> ts, bs;
        for(int j = 0; j < N; j++) {
            int c = art[i][j];
            if(ts.count(c) != 0) {
                c2r[c][2] = j;
            } else if (bs.count(c) != 0) {
                c2r[c][5] = c2r[c][2] = max(j, c2r[c][2]);
            } else if (c2r[c][2] != -1) {
                c2r[c][3] = i;
                bs.insert(c);
                c2r[c][4] = min(c2r[c][1], j);
                c2r[c][5] = min(c2r[c][1], j);
            } else {
                c2r[c][0] = i;
                c2r[c][1] = j;
                c2r[c][4] = j;
                c2r[c][2] = j;
                c2r[c][5] = j;
                ts.insert(c);
            }
        }
    }

    for(int c : vc) {
        c2r[c][2] = c2r[c][5] =  max(c2r[c][2], c2r[c][5]);
        c2r[c][1] = c2r[c][4] = min(c2r[c][1], c2r[c][4]);
        if(c2r[c][2] == -1) {
            c2r[c][2] = c2r[c][5] = c2r[c][1];
        } if(c2r[c][3] == -1) {
            c2r[c][3] = c2r[c][0];
        }
    }

    dbg << vc.size() << endl;

#ifdef DEV_ENV
    for(int c : vc) {
        cout << c << ": ";
        in(6, 0) {
            cout << c2r[c][i] <<  " ";
        }
        cout << endl;
    }
#endif


    for(int c : vc) {
        for(int x = c2r[c][0]; x <= c2r[c][3]; x++) {
            for(int y = c2r[c][1]; y <= c2r[c][2]; y++) {
                dbg << c << ": " << x << " " << y << " " << art[x][y] << endl;
                if(art[x][y] != c && art[x][y] != 0) {
                    dbg << "not first: " << art[x][y] << endl;
                    pa.erase(art[x][y]);
                }
            }
        }
    }
    
    cout << pa.size();

	return 0;
}

