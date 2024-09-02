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

bool doIntersect(vector<int>* first, vector<int>* second) {
    bool intersect = false;

    // Fix the order of intervals
    if((*first)[0] > (*second)[0]) {
        vector<int>* tmp = first;
        first = second;
        second = tmp;
    }

    if((*first)[1] > (*second)[0] && (*first)[1] < (*second)[1])
        intersect = true;

    return intersect;
}

int main() {
    freopen("circlecross.in", "r", stdin);
    //freopen("circlecross.out", "w", stdout);
    int N = 26;
    char chars[N];
    in(N, 0) {
        chars[i] = 'A' + i;
    }

    map<char, vector<int>> lp;
    in(N*2, 0) {
        char l;
        cin >> l;
        lp[l].push_back(i);
    }

    int c = 0;

    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            if(doIntersect(&lp[chars[i]], &lp[chars[j]])) c++;

/*
            if (lp[chars[j]][0] < lp[chars[i]][0] && lp[chars[j]][1] > lp[chars[i]][0] && lp[chars[j]][1] < lp[chars[i]][1]) {
                //cout << chars[i] << " " << chars[j] << " " << "i>j" << endl;
                c++;
            } else if (lp[chars[j]][1] > lp[chars[i]][1] && lp[chars[j]][0] > lp[chars[i]][0] && lp[chars[j]][0] < lp[chars[i]][1]) {
                //cout << chars[i] << " " << chars[j] << " " << "i<j" << endl;
                c++;
        }
*/
        }
    }

    cout << c;

    return 0;
}

