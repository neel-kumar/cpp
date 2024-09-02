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
string to_string(const set<T>& s)
{
    return to_string(s.begin(), s.end());
}

template<typename T>
string to_string(const set<T>* s)
{
    return to_string(s->begin(), s->end());
}

int main() {
	freopen("tttt.in", "r", stdin);
	//freopen("tttt.out", "w", stdout);
    
    char b[3][3];
    for(int i = 0; i < 3; i++) {
        string rc;
        cin >> rc;
        b[i][0] = rc[0];
        b[i][1] = rc[1];
        b[i][2] = rc[2];
    }

    int ww[8][6] = {{0,0,0,1,0,2},{1,0,1,1,1,2},{2,0,2,1,2,2},{0,0,1,0,2,0},{0,1,1,1,2,1},{0,2,1,2,2,2},{0,0,1,1,2,2},{0,2,1,1,2,0}};

    int s = 0;
    int d = 0;

    set<char> tsone;
    set<string> tstwo;

    for(int i = 0; i < 8; i++) {
        set<char> cs;
        bool sd = false;

        for(int j = 0; j < 3; j++) cs.insert(b[ww[i][j*2]][ww[i][j*2+1]]);

        if(cs.size() == 1) {
            s++;
            sd = true;
            tsone.insert(*cs.begin());
        } else if (cs.size() == 2) {
            d++;
            sd = true;
            tstwo.insert(to_string(cs));
        }
    }
        cout << tsone.size() << endl;
        cout << tstwo.size() << endl;

	return 0;
}

