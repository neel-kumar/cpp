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
string to_string(T *a, int size) {
    return to_string(vector<T>(a, a+size));
}

int fb_neel(int *l, int N) {
    bool nb = true;
    in(N-1, 0) if(l[i] > l[i+1]) nb = false;
    if(nb) return -1;

    in(N, 0) {
        bool isb = true;
        for(int j = 0; j < N-1; j++) {
            if(j == i) continue;
            else if(l[j] > l[j+1]) isb = false;
        }
        if(isb) return i;
    }
    return -2;
}

// l can have duplicate integers
bool is_sorted(const int* const l, const int N, const int ignore) {
    bool sorted = true;
    int prev = ignore != 0 ? l[0] : l[1];

    for(int i = 0; i < N && sorted; i++) {
        if(i != ignore) {
            if(l[i] >= prev) {
                prev = l[i];
            } else {
                sorted = false;
            }
        }
    }

    return sorted;
}

// Return -1 if l is already sorted,
// else return the index of Bessie
int fb(int *l, int N) {
    int ib = is_sorted(l, N, -1) ? -1 : 0;

    if(ib != -1) {
        for(int i = 0; i < N; i++) {
            if(is_sorted(l, N, i)) {
                ib = i;
                break;
            }
        }
    }

    return ib;
}

int fbsdumdum(int *l, int N, int bp) {
    bool isg = true;
    if(bp == N-1) isg = false;
    else if(bp == 0) isg = true;
    else if(l[bp] < l[bp-1] && l[bp] < l[bp+1]) isg = false;
    if(isg) {
        for(int i = bp; i <= N; i++) {
            if(i == 0 && l[i] >= l[bp]) return 0;
            else if(i == N && l[i] <= l[bp]) return N;
            else if(l[i] <= l[bp] && l[i+1] >= l[bp]) return i;
        }
    } else {
        for(int i = bp; i >= 0; i--) {
            if(i == 0 && l[i] >= l[bp]) return 0;
            else if(i == N && l[i] <= l[bp]) return N;
            else if(l[i] >= l[bp] && l[i+1] <= l[bp]) return i;
        }
    }
    return -1;
}

// Return the index at which value at bp should be inserted
// to minimize the distance from bp
int fbs(int *l, int N, int bp) {
    // cout << "(In fbs - bp: " << bp << ") ";
    int mini = -1, maxi = -1;
    const int bh = l[bp];

    // Calculate min index and max index where bh can
    // be inserted, so that the list l will be sorted.
    for(int i = 0; i < N; i++) {
        if(i != bp) {
            if(mini == -1 && l[i] >= bh) {
                mini = i;
            }

            if(l[i] == bh) {
                maxi = i + 1;
            }
        }
    }
    
    // cout << "(mini: " << mini << ", maxi: " << maxi << ") ";

    int fpos = mini;
    if(maxi != -1) {
        if(abs(bp - mini) > abs(bp - maxi)) {
            fpos = maxi;
        }
    }

    return fpos;
}

int fbs_neel(int *l, int N, int bp) {
    bool g;
    if(bp == 0) g = true;
    else if (bp == N-1) g = false;
    else if (l[bp] < l[bp-1]) g = false;
    else g = true;
    int ans = 0;

    if(g) {
        for(int i = bp+1; i < N; i++) {
            if(l[i] >= l[bp] && l[i-1] <= l[bp]) {
                ans = i;
                break;
            }
        }   
    } else {
        for(int i = bp-1; i >= 0; i--) {
            if(l[i] <= l[bp] && l[i+1] >= l[bp]) {
                ans = i;
                break;
            }
        }
    }
    return ans;
}

int ans(int*l, int bp, int bsp) {
    int start = 0, end = 0;
    if(bsp < bp) {
        start = bsp;
        end = bp;
    } else {
        start = bp + 1;
        end = bsp;
    }

    int prev = l[start];
    int an = 1;

    for(int i = start; i < end; i++) {
        if(l[i] != prev) {
            ++an;
            prev = l[i];
        }
    }

    return an;
}

int main() {
	freopen("outofplace.in", "r", stdin);
	//freopen("outofplace.out", "w", stdout);

    int N;
    cin >> N;
    int l[N];
    in(N, 0) {
        int h;
        cin >> h;
        l[i] = h;
    }

    int bp = fb(l, N);

    if(bp == -1) {
        cout << 0 << endl;
    } else {
        int bsp = fbs(l, N, bp);
        // cout << bp << " " << bsp << endl;
        cout << ans(l, bp, bsp) << endl;
    }

    // int a[] = {2, -1, 0, 0, 2, 2};
    // cout << "a: " << fbs(a, 6, fb(a, 6)) << endl;

	return 0;
}

