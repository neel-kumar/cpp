#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {2,4,6,8};

    a[0] = 5;
    a[3]++;

    for(int i = 0; i < 4; i++) {
        cout << a[i] << " ";
    }

    a.pop_back();
    a.push_back(0);
    cout << "\nSize of a: " << a.size() << "\n";
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}
