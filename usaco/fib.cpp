#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int input;
    cout << "Enter n: ";
    cin >> input;
    cout << "Fib(" + to_string(input) + ") = " + to_string(fib(input)) + "\n";

    return 0;
}
