#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int nm = 0;
vector<pair<int, int>> ms;

void mvtower(int s, int d, int o, int n) {
    if(n==1) ms.push_back(make_pair(s, d));
    else {
        mvtower(s, o, d, n-1);
        ms.push_back(make_pair(s, d));
        mvtower(o, d, s, n-1);
    }
    nm++;
}

int main() {
    int n;
    cin >> n;
    mvtower(1, 3, 2, n);
    cout << nm << "\n";

    for(auto i : ms) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}
