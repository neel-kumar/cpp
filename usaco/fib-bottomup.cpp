#include <bits/stdc++.h>

using namespace std;

map<int, int> memo;

int fib(int n) {
    for(int i = 2; i <= n; i++) {
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}

int main() {
    memo[0] = 1;
    memo[1] = 1;

    int input;
    cout << "Enter n: ";
    cin >> input;
    cout << "Fib(" + to_string(input) + ") = " + to_string(fib(input)) + "\n";


    return 0;
}
