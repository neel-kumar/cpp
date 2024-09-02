#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<long long, long long> fh, sh;
vector<long long> h1, h2;
long long n, x;

int main() {
    cin >> n >> x;
    for(long long i = 0; i < (n/2); i++) {
        h1.push_back(0);
        cin >> h1[i];
    }
    for(long long i = (n/2); i < n; i++) {
        h2.push_back(0);
        cin >> h2[i-(n/2)];
    }
    long long h1s = h1.size(), h2s = h2.size();

    for(long long i = 0; i < (1<<h1s); i++) {
        long long c = 0;
        for(long long k = 0; k < h1s; ++k) {
            if((i & (1 << k)) != 0) {
                c += h1[k];
            }
        }
        if(fh.count(c) == 0) fh[c] = 1;
        else fh[c]++;
    }
    for(long long i = 0; i < (1<<h2s); i++) {
        long long c = 0;
        for(long long k = 0; k < h2s; ++k) {
            if((i & (1 << k)) != 0) {
                c += h2[k];
            }
        }
        if(sh.count(c) == 0) sh[c] = 1;
        else sh[c]++;
    }

    long long ans = 0;
    for(const auto &i : fh) {
        if(i.first == x) ans += i.second;
        else if(i.first == 0) ans += sh[x];
        else if(sh.count(x-i.first) != 0) ans += (i.second*sh[x-i.first]);
    }
    cout << ans;

    return 0;
}

