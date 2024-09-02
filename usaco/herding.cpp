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
	freopen("herding.in", "r", stdin);
	//freopen("herding.out", "w", stdout);
    int c[3];
    cin >> c[0] >> c[1] >> c[2];
    sort(c, c+3);

    if(c[0]+1 == c[1] && c[1]+1 == c[2]) {
        cout << 0 << endl << 0;
        return 0;
    } else if(c[0]+2 == c[1] || c[1]+2 == c[2]) cout << 1 << endl;
    else cout << 2 << endl;

    cout << max(c[1]-c[0], c[2]-c[1])-1;
	return 0;
}

