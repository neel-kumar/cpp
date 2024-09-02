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

int main() {
	freopen("blist.in", "r", stdin);
	//freopen("blist.out", "w", stdout);
    int N;
    cin >> N;
    int tl[N][3];
    in(N, 0) {
        int a,b,c;
        cin >> a >> b >> c;
        tl[i][0] = a;
        tl[i][1] = b;
        tl[i][2] = c;
    }

    /*
    int bt[N];
    in(N, 0) {
        bt[i] = tl[i][2];
        for(int j = 0; (j < N && j != i); j++) {
            if((tl[j][0] < tl[i][1] && tl[j][0] > tl[i][0]) || (tl[j][1] < tl[i][1] && tl[j][1] > tl[i][0])) bt[i] += tl[j][2];
        }
    }

    int max = 0;
    in(N, 0) {
        if(bt[i] > max) max = bt[i];
    }
    */

    int ans = 0;
    in(1001, 1) {
        int nb = 0;
        for(int j = 0; j < N; j++) if(tl[j][0] <= i && tl[j][1] >= i) nb += tl[j][2];
        if(nb > ans) ans = nb;
    }

    cout << ans;
	return 0;
}

