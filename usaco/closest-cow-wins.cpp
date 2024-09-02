#include <bits/stdc++.h>
#include <utility>

using namespace std;
using ld = long double;
using ll = long long;

int k, m, n;
vector<pair<int, int>> field;
vector<ll> vals;

ll get_sum(int s, int e) {
    ll ans = 0;
    for(int i = s; i < e; i++) {
        if(field[i].second != -1) {
            ans += field[i].second;
        }
    }
    return ans;
}

ll get_sliding_sum(int s, int e) {
    ll ans = 0;
    for(int i = s; field[i].first < e; i++) {
        if(field[i].second != -1) {
            ans += field[i].second;
        }
    }
    return ans;
}

ll max_interval(int s, int e) {
    int sws = ceil((field[e].first - field[s].first)/2), swl, swr;
    ll mx = 0;

    for(swl = s; swl + sws <= e; swl++) {
        swr = swl + sws;
        mx = max(mx, get_sliding_sum(swl, swr));
    }

    return mx;
}

void process_interval(int s, int e) {
    if(s == 0 && e == 0) {
        // Do nothing
    } else if (s == 0) {
        // Beginning interval
        vals.push_back(get_sum(s, e));
    } else if (e == field.size()) {
        // end interval
        if(s != field.size() - 1) {
            vals.push_back(get_sum(s, e));
        }
    } else {
        // internal interval
        ll sum = get_sum(s, e);
        ll m = max_interval(s, e);
        vals.push_back(m);
        vals.push_back(sum - m);
    }
}

int main() {
    cin >> k >> m >> n;
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        field.push_back(make_pair(a, b));
    }
    for(int i = 0; i < m; i++) {
        int a, b=-1; cin >> a;
        field.push_back(make_pair(a, b));
    }

    sort(field.begin(), field.end());

    int s = 0, e = 0;
    while(e < field.size()) {
        if(field[e].second == -1) {
            // Found the end of interval
            // Process this interval
            process_interval(s, e);
            // Prepare for next interval
            s = e;
        }

        e++;

    }

    // Process end interval
    process_interval(s, e);

    sort(vals.begin(), vals.end());
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += vals[vals.size()-i];
    }
    cout << ans << "\n";
    return 0;
}
