/*
 * input --> 5: 1, 2, 3, 4, 5
 * 1: 3, 4, 5
 * 2: 4, 5
 * 3: 1, 5
 * 4: 1, 2
 * 5: 1, 2, 3
 *
 * input --> 3: 1, 2, 3
 * 1: 3
 * 2: Null
 * 3: 1
 *
 * WRONG: BF#1 O(n^2): calc possible per element, iterate over each element
 * O(n): group even and odds, put one after the other, check if it works
*/

#include <iostream>
#include <math.h>

using namespace std;

int n;

int main() {
    cin >> n;
    if(n < 4 && n > 1) {
        cout << "NO SOLUTION";
        return 0;
    } else {
        for(int i = 2; i <= n; i+=2) cout << i << " ";
        for(int i = 1; i <= n; i+=2) cout << i << " ";
    }

    return 0;
}
