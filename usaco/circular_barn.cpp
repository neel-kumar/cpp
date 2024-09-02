#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<bool> isPrime(5000001, true);
    //vector<bool> isPrime(10001, true);
    for (int i = 2; i <= 5000000; i++)
        if (isPrime[i])
            for (int j = i * 2; j <= 5000000; j += i)
                isPrime[j] = false;

    vector<int> turns(5000001, 0);
    // calculate turns, which is the minimum number of turns necessary to empty out the farm at index i.

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> rooms(n);
        for (int j = 0; j < n; j++)
            cin >> rooms[j];

        bool isJohn = true;
        int minTurns = 2000000000;
        for (int j = 0; j < n; j++) {
            int currentTurns = turns[rooms[j]] / 2;
            if (minTurns > currentTurns) {
                minTurns = currentTurns;
                if (turns[rooms[j]] % 2 == 1)
                    isJohn = true;
                else
                    isJohn = false;
            }
        }

        cout << "Farmer ";
        if (isJohn) cout << "John";
        else cout << "Nhoj";
        cout << endl;
    }

    return 0;
}
