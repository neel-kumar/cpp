#include <bits/stdc++.h>

using namespace std;

int a[101]; // In this case the max size of the map is 100
int asize = 0;

int main() {
    // Maps
    cout << "WITH MAPS\n";
    map<int, int> m;
    m[50] = 3;
    m[100] = 4;
    m[50]--;
    cout << "Count of 30: " << m.count(30) << "\n";
    cout << "Count of 100: " << m.count(100) << "\n";
    cout << "Value of 50: " << m[50] << "\n";
    cout << "# of elements in map: " << m.size() << "\n";

    cout << "\nWITH ARRAYS\n";
    // Using arrays
    a[50] = 3;
    asize++;
    a[100] = 4;
    asize++;
    a[50]--;
    cout << "Count of 30: " << (a[30] != 0) << "\n";
    cout << "Count of 100: " << (a[100] != 0) << "\n";
    cout << "Value of 50: " << a[50] << "\n";
    cout << "# of elements in map/array: " << asize << "\n";
    
    return 0;
}
