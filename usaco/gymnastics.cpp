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

int ans(int N, int K, int g[10][21]) {
    int ans = 0;
    for(int i = N; i > 0; i--) {
        for(int j = 1; j < i; j++) {
            bool isp = true;
            bool ig = true;
            if(g[0][i] < g[0][j]) ig = false;
            for(int k = 1; k < K; k++) {
                bool ign = true;
                if(g[k][i] < g[k][j]) ign = false;
                if(ign != ig) isp = false;
            }
            if(isp) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
	freopen("gymnastics.in", "r", stdin);
	//freopen("gymnastics.out", "w", stdout);

    int N, K;
    cin >> K >> N;
    int g[10][21];
    in(K, 0) {
        for(int j = 0; j < N; j++) {
            int c;
            cin >> c;
            g[i][c] = j;
        }
    }

    cout << ans(N, K, g);
	return 0;
}

