#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

//pair<int, int> b2d[100001];
int N;
//vector<int> rotarr;

/*long long test() {
    long long nmoo = 0;
    set<int> deportedcows;
    for(int i : rotarr) {
        if(deportedcows.count(b2d[i].first) == 0) {
            deportedcows.insert(i);
            nmoo += b2d[i].second;
        }
    }

    return nmoo;
}*/

int main() {
    cin >> N;
    int dumbsum = 0;;
    int dumbans = INT32_MAX;
    for(int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        //rotarr.push_back(x);
        dumbans = min(dumbans, y);
        dumbsum += y;
        //b2d[i] = make_pair(x, y);
    }

    /*long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(test(), ans);
        rotate(rotarr.begin(), rotarr.begin()+rotarr.size()-1, rotarr.end());
    }
    */

    cout << dumbsum-dumbans;
    return 0;
}
