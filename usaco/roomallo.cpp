#include <bits/stdc++.h>
#include <functional>
#include <utility>

using namespace std;

int n;
vector<tuple<int, bool, int>> sl; // 0=s, 1=e

bool cco(tuple<int, bool, int> a, tuple<int, bool, int> b) {
    if(get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    else return get<0>(a) < get<0>(b);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sl.push_back(make_tuple(a, false, i));
        sl.push_back(make_tuple(b, true, i));
    }
    sort(sl.begin(), sl.end(), cco);

    int aa[200000];
    stack<int> fr;
    vector<bool> rooms;
    int ans = 0, c = 0;
    for(auto i : sl) {
        if(get<1>(i)) {
            c--;
            fr.push(aa[get<2>(i)]);
        } else {
            c++;
            if(fr.empty()) aa[get<2>(i)] = c;
            else {
                aa[get<2>(i)] = fr.top();
                fr.pop();
            }
        }
        ans = max(ans, c);
    }

    cout << ans << "\n";
    for(int i = 0; i < n; i++) cout << aa[i] << " ";

    return 0;
}
