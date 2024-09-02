#include <bits/stdc++.h>

using namespace std;

bool a[11]; // In this case the max size of the set is 100
int asize = 0;

int main() {
    // Sets
    cout << "WITH SETS\n";
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(1);
    s.erase(1);
    cout << "Count of 30: " << s.count(3) << "\n";
    cout << "Count of 10: " << s.count(10) << "\n";
    cout << "# of elements in set: " << s.size() << "\n";

    cout << "\nWITH ARRAYS\n";
    // Using arrays
    a[10] = true;
    asize++;
    a[5] = true;
    asize++;
    a[1] = true;
    asize++;
    a[1] = false;
    asize--;
    cout << "Count of 30: " << a[3] << "\n";
    cout << "Count of 100: " << a[10] << "\n";
    cout << "# of elements in set/array: " << asize << "\n";

    return 0;
}
