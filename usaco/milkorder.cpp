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

void io(string f) {
    freopen((f + ".in").c_str(), "r", stdin);
#ifndef DEV_ENV
    freopen((f + ".out").c_str(), "w", stdout);
#endif
}

int N;
int M;
int sh[101];
int K;

int c2p[101]; // cow -> position
int p2c[101]; // position -> cow

int getFirstAvailable() {
    in(N+1, 1) {
        if(p2c[i] == -1) {
            return i;
        }
    }

    throw new runtime_error("Cannot find empty space");
}

int getLastAvailableBefore(int l) {
    for(int i = l - 1; i >= 1; i--) {
        if(p2c[i] == -1) {
            return i;
        }
    }

    // Not available
    return -1;
}

bool canPlaceSH(void) {
    bool valid = true;

    vector<int> pcs;

    int rightmost = N + 1;
    for(int i = M - 1; i >= 0; i--) {
        // Place ith cow, if not already placed
        int c = sh[i];
        if(c2p[c] == -1) {
            // Place the cow at first available position
            int p = getLastAvailableBefore(rightmost);
            if(p == -1) {
                valid = false;
                break;
            }
            c2p[c] = p;
            p2c[p] = c;
            pcs.push_back(c);
        } else if(i < (M - 1) && (c2p[c] > c2p[sh[i + 1]])) {
            valid = false;
            break;
        }

        rightmost = c2p[c];
    }

    // Reset the data structures
    for(int c: pcs) {
        p2c[c2p[c]] = -1;
        c2p[c] = -1;
    }

    return valid;
}

int main() {
    io("milkorder");
    cin >> N >> M >> K;

    // Initialize variables
    in(N+1, 0) {
        c2p[i] = p2c[i] = -1;
    }

    in(M, 0) {
        int c;
        cin >> c;
        sh[i] = c;
    }

    in(K, 0) {
        int c, p;
        cin >> c >> p;

        c2p[c] = p;
        p2c[p] = c;
    }

    // if cow 1 is already placed, return
    if(c2p[1] != -1) {
        cout << c2p[1];
        return 0;
    }

    // Now place cow 1 from left to right in empty places and the first valid placement is the answer.
    in(N+1, 1) {
        if(p2c[i] == -1) {
            dbg << "Placing cows 1 at " << i << endl;
            p2c[i] = 1;
            c2p[1] = i;
            if(canPlaceSH()) {
                cout << i;
                return 0;
            } else {
                p2c[i] = -1;
                c2p[1] = -1;
            }
        }
    }

    // throw new runtime_error("Invalid input");
    cout << "Invalid input" << endl;

    return 0;
}
