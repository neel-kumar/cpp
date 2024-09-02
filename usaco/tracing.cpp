#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <list>
#include <string>
#include <tuple>
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

pair<int, int> sim1(int tl[251][2], int rc, string end) {
    pair<int, int> ans;
    ans.second = 0;
    ans.first = 0;
    set<int> ics;
    ics.insert(rc);
    in(252, 1) {
        if (tl[i][1] == rc) {
            int c = tl[i][0];
            tl[i][0] = rc;
            tl[i][1] = c;
        }
        if (tl[i][0] == -1) continue;
        else if (ics.count(tl[i][0]) == 0 && ics.count(tl[i][1]) == 0 && end[tl[i][0]] == '1' && end[tl[i][1]] == '1') {
            ans.second = -2;
            ans.first = -2;
            return ans;
        } else if (tl[i][0] == rc) {
            if (end[tl[i][1]] == '0') {
                ics.erase(rc);
            } else if (ics.count(tl[i][1]) == 0 && end[tl[i][1]]) {
                if (ics.count(rc) == 0) {
                    ans.second = -2;
                    ans.first = -2;
                    return ans;
                } else {
                    ics.insert(tl[i][1]);
                    ans.first++;
                    ans.second++;
                }
            } else if (ics.count(rc) != 0 && ics.count(tl[i][1])) ans.second++;
        } else if (end[tl[i][0]] == '1' && end[tl[i][1]] == '1') {
            if (ics.count(tl[i][0]) == 0) ics.insert(tl[i][0]);
            else if (ics.count(tl[i][1]) == 0) ics.insert(tl[i][1]);
        }
    }
    if(ics.count(rc) != 0) ans.second = -1;
    return ans;
}

tuple<string, int, int> sim(int tl[251][2], int rc, string end) {
    tuple<string, int, int> ans = make_tuple("", 0, 0);
    for(char i : end) get<0>(ans) += "0";
    get<0>(ans)[rc] = '1';
    in(252, 1) {
        if(tl[i][1] == rc) {
            tl[i][1] = tl[i][0];
            tl[i][0] = rc;
        }
        if(tl[i][0] == rc && get<2>(ans) >= 0) {
            if(get<0>(ans)[tl[i][0]-1] == '1') get<1>(ans)--;
            get<1>(ans)++;
            get<2>(ans)++;
        }
        if(get<0>[tl[i][0]-1] == '1' || get<0>[tl[i][1]-1] == '1') {
            get<0>(ans)[tl[i][0]] = '1';
            get<0>(ans)[tl[i][1]] = '1';
        }

    }
    return ans;
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
    }

    vector<int> ic;
    in(N, 0) if (ci[N] == 1) ic.push_back(i+1);

    tuple<int, int, int> ans;
    ans = make_tuple(0, 251, -1);
    for(int c : ic) {
        pair<int, int> simans;
        simans = sim(t2i, c, ci);
        if (simans.first != -2) {
            if (simans.first < get<1>(ans)) get<1>(ans) = simans.first;
            if (simans.second > get<2>(ans)) get<2>(ans) = simans.second;
            if (simans.second == -1) get<2>(ans) = -1;
            get<0>(ans)++;
        }
    }

    cout << get<0>(ans) << " " << get<1>(ans) << " ";
    if(get<2>(ans) == -1) cout << "Infinity";
    else cout << get<2>(ans);
	return 0;
}


