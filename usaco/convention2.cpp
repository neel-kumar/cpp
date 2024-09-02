#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<vector<int>> ats;

int nlte(int atsi, int curt) {
    int ret = 0;
    int atss = ats.size();
    for(int i = atsi; i < atss; i++) {
        if(ats[i][0] <= curt) {
            ret++;
        } else {
            break;
        }
    }
    return ret;
}

bool acomp(vector<int> i, vector<int> j) {
    return i[0] < j[0];
}

bool scomp(vector<int> i, vector<int> j) {
    return i[2] < j[2];
}

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    // cout << "In Main" << endl;

    int N;
    cin >> N;
    int s = 1;
    for(int i = 0; i < N; i++) {
        int a, t;
        cin >> a >> t;
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(t);
        tmp.push_back(s);
        ats.push_back(tmp);
        s++;
    }

    // Sort the vector by arrival time
    sort(ats.begin(), ats.end(), acomp);

    set<vector<int>, decltype(&scomp)> ss(&scomp);
    int mw = 0, curt = 0, atsi = 0, nc = 0;

    while(nc < N) {
        // cout << "Curt is: " << curt << endl;

        // Count the number of elements whose arrival time is <= curt in ats. If this number is 0 and atsi < ats.size(), assign curt to "a" of ats[atsi]
        int tnc = nlte(atsi, curt);
        // cout << "tnc is: " << tnc << endl;
        if(tnc == 0 && ss.empty() && atsi < N) {
            curt = ats[atsi][0];
            // cout << "Changed curt to " << curt << endl;
        }

        // Fetch the list of cows whose arrival time is <= curt in ats (advance atsi) into ss
        tnc = nlte(atsi, curt);
        // cout << "Before insert, ss size: " <<  ss.size() << endl;
        for(int i = 0; i < tnc; i++) {
            ss.insert(ats[atsi++]);
        }

        // cout << "Number of cows added to ss: " << tnc << endl;

        // cout << "ss size: " <<  ss.size() << endl;
        // assert(!ss.empty());

        // Process (advance curt and keep track of mw) first cow in ss and increment nc
        auto f = ss.begin();
        const vector<int> c = *f;
        // cout << "Processing cow: " << c[2] << endl;
        mw = max(mw, curt - c[0]);
        nc++;
        curt += c[1];
        ss.erase(f);
    }

    cout << mw;
    return 0;
}
