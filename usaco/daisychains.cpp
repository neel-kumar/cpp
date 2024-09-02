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
    freopen("daisychains.in", "r", stdin);
#endif
    int nf;
    cin >> nf;
    dbg << nf << endl;
    vector<int> flowers;
    in(nf, 0) {
        int f;
        cin >> f;
        flowers.push_back(f);
    }
    int ans = 0;
    in(nf, 0) {
        int accuC = 0, accuS = 0;
        set<int> accuF;
        for(int j = i; j < nf; j++) {
            accuC++;
            accuS += flowers[j];
            dbg << i << " " << j << " " << accuS/accuC << endl;
            accuF.insert(flowers[j]);
            if(accuF.count(accuS/accuC) != 0 && accuS % accuC == 0) ans++;
        }
    }
    cout << ans;
	return 0;
}

