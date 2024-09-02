#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool xcomp(pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
}

bool ycomp(pair<int, int> i, pair<int, int> j) {
    return i.second < j.second;
}

int main() {
    //freopen("rps.in", "r", stdin);
    int N;
    cin >> N;
    vector<pair<int, int>> byx;
    vector<pair<int, int>> byy;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        byx.push_back(make_pair(x, y));
        byy.push_back(make_pair(x, y));
    }
    sort(byx.begin(), byx.end(), xcomp);
    sort(byy.begin(), byy.end(), ycomp);
    map<pair<int, int>, pair<int, int>> c2p;
    for(int i = 0; i < N; i++) {
        c2p[byx[i]].first = i;
        c2p[byy[i]].second = i;
    }
    
    long long ans = pow(2, N);
    for(int i = N-1; i > 0; i--) {
        //cout << byx[i].first << " " << byx[i].second << " " << i-1 << " " << c2p[byx[i]].second-1 << endl;
        if(byy[i-1] == byx[c2p[byx[i]].second-1]) {
            ans = ans - (pow(2, min(i-1, c2p[byy[i]].second-1))-1);
        }
    }
    cout << ans;
	return 0;
}

