#include <bits/stdc++.h>

using namespace std;

map<int, int> memo;

int fib(int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else if(memo.count(n) != 0) {
        return memo[n];
    } else {
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
}

int main() {
    int input;
    cout << "Enter n: ";
    cin >> input;
    cout << "Fib(" + to_string(input) + ") = " + to_string(fib(input)) + "\n";

    return 0;
}
