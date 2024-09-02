#include <iostream>

using namespace std;

long long power(long long y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return (power(y/2) % 1000000007) * (power(y/2) % 1000000007);
    else
        return 2 * (power(y-1) % 1000000007);
}

int main() {
    long long n;
    cin >> n;
    cout << (power(n) % 1000000007);
    return 0;
}
