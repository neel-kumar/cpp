#include <bits/stdc++.h>

using namespace std;

map<int, int> pf;
set<int> factors;
int n;

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        if(pf.count(2) == 0) {
            pf[2] = 0;
        }
        factors.insert(2);
        pf[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            if(pf.count(i) == 0) {
                pf[i] = 0;
            }
            factors.insert(i);
            pf[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2) {
        pf[n] = 1;
        factors.insert(n);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, ans = 1;
        cin >> x;
        primeFactors(x);
        for (int i : factors) {
            ans *= pf[i]+1;
            pf[i] = 0;
        }
        factors.clear();
        cout << ans << "\n";
    }

    return 0;
}
