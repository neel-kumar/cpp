#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if((a+b)%3 != 0 || a > 2*b || b > 2*a) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
