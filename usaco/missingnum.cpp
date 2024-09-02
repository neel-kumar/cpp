#include <iostream>

using namespace std;

long long n;

int main() {
    cin >> n;
    long long o2n = (n*(n+1)) / 2;
    long long s = 0;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    cout << (o2n-s);

    return 0;
}
