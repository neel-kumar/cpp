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
#include <unordered_set>

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

inline void get_substr(const string& s, int a, int b, int c, ostringstream& os) {
    os << s[a] << s[b] << s[c];
}

void get_strings(const vector<string>& s, int a, int b, int c, unordered_set<string>& strs) {
    for(const string& tmp: s) {
        ostringstream os;
        get_substr(tmp, a, b, c, os);
        strs.insert(os.str());
    }
}

int main() {
	freopen("cownomics.in", "r", stdin);
	// freopen("cownomics.out", "w", stdout);
    int N, M;
    // vector<string> s;
    // vector<string> p;


    cin >> N >> M;

    int g2n1['Z'];
    g2n1[0 + 'A'] = 0;
    g2n1[0 + 'C'] = 1;
    g2n1[0 + 'G'] = 2;
    g2n1[0 + 'T'] = 3;


    int s1[N][M];
    int p1[N][M];

    in(N, 0) {
        string c;
        cin >> c;
        for(int j = 0; j < M; j++) {
            s1[i][j] = g2n1[c[j]];
        }
    }

    in(N, 0) {
        string c;
        cin >> c;
        for(int j = 0; j < M; j++) {
            p1[i][j] = g2n1[c[j]];
        }
    }

    int ans = 0;
    for(int a = 0; a < M-2; a++) {
        for(int b = a+1; b < M-1; b++) {
            for(int c = b+1; c < M; c++) {
                bool isu = true;

                bool x[64] = {false};
                // for(int i = 0; i < 64; i++) x[i] = false;

                for(int i = 0; i < N; i++) {
                    int num = s1[i][a]*16 + s1[i][b]*4 + s1[i][c];
                    x[num] = true;
                }

                for(int i = 0; i < N; i++) {
                    int num = p1[i][a]*16 + p1[i][b]*4 + p1[i][c];
                    if(x[num]) {
                        isu = false;
                        break;
                    }
                }

                if(isu) ans++;
            }
        }
    }

    cout << ans;
	return 0;
}

