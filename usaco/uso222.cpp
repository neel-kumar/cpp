#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;
set<set<char>> tsubset;
vector<set<char>> qs;
int Q;
string s, t;
vector<bool> ans;

bool test(set<int> si) {
}

int main() {
    cin >> s >> t;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        string s;
        set<char> ss;
        cin >> s;
        for(char c : s) {
            ss.insert(c);
        }
        qs.push_back(ss);
    }

    for(set<char> si : qs) {
        if(tsubset.count(si) != 0) {
            ans.push_back(true);
        } else {
            if(test(si)) {
                addSubsets(si);
            }
        }
    }

    string finans = "";
    for(bool i : ans) {
        if(i) {
            finans += "Y";
        } else {
            finans += "N";
        }
    }

    cout << finans;

    return 0;
}
