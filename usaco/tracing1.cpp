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
	freopen("tracing.in", "r", stdin);
	//freopen("tracing.out", "w", stdout);
    
    int N, T;
    string ci;
    int t2i[251][2];

    for(int i = 0; i < 251; i++) for(int j = 0; j < 2; j++) t2i[i][j] = -1;

    cin >> N >> T >> ci;
    //cout << "Input args: N: " << N << " T: " << T << " ci: " << ci << endl;

    in(T, 0) {
        int t, x, y;
        cin >> t >> x >> y;
        t2i[t][0] = x;
        t2i[t][1] = y;
        //cout << t2i[t][0] << endl;
    }

    int c2s[N];
    set<int> nr1;
    in(N, 0) c2s[i] = 0;
    in(250, 0) {
        int x = t2i[i][0]-1;
        int y = t2i[i][1]-1;
        if (x == -1) continue;
        else if (ci[x] == '1' && ci[y] == '1') {
            //cout << "11 " << x << " " << y << " " << i << endl;
            if (nr1.count(x) == 0) c2s[y]++;
            else if (nr1.count(y) == 0) c2s[x]++;
            else {
                c2s[x]++;
                c2s[y]++;
            }
        } else if (ci[x] == '0' && ci[y] == '1') {
            //cout << "01 " << x << " " << y << " " << i << endl;
            if (c2s[y] > 0) c2s[y] *= -1;
            else if (c2s[y] == 0) nr1.insert(y);
        } else if (ci[x] == '1' && ci[y] == '0') {
            //cout << "10 " << x << " " << y << " " << i << endl;
            if (c2s[x] > 0) c2s[x] *= -1;
            else if (c2s[x] == 0) nr1.insert(x);
        }
    }
    int n, min, max;
    n = 0;
    for(int c : c2s) {
        //cout << c << endl;
        if(min == 0) min = c;
        if(c > 0) {
            n++;
            max = -1;
            if (c < min) min = c;
        } else if(c < 0) {
            n++;
            if (c*-1 < min) min = c;
        }
    }

    cout << n << " " << min << " ";
    if(max < 0) cout << "Infinity";
    else cout << max;
	return 0;
}

