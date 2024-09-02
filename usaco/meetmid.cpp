// calculate all subsets for each half and combine them with maps, add all together

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

    return 0;
}
