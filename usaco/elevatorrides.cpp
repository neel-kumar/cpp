#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> w;
pair<int, int> memo[1<<20];

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        w.push_back(0);
        cin >> w.back();
    }

    memo[0] = make_pair(0, x);
    for(int i = 1; i < (1<<n); i++) {
        pair<int, int> best = make_pair(INT8_MAX, INT8_MAX);
        for(int j = 0; j < n; j++) {
            if(i & (1<<j)) {
                int k = i^(1<<j);
                pair<int, int> t = memo[k];
                if(t.second + w[j] > x) {
                    t.first++;
                    t.second = w[j];
                } else t.second += w[j];
                if(t < best) best = t;
                if(i == -1) {
                    cout << "J: " << j << " " << t.first << " " << t.second << "\n";
                }
            }
        }
        memo[i] = best;
        //cout << i << " " << memo[i].first << " " << memo[i].second << "\n";
    } 
    cout << memo[(1<<n)-1].first;
    return 0;
}
