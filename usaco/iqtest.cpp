#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int N;

int main() {
    cin >> N;
    vector<int> e, o;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if(x%2 == 0) {
            e.push_back(i+1);
        } else {
            o.push_back(i+1);
        }
    }
    if(o.size() == 1) {
        cout << o[0];
    } else {
        cout << e[0];
    }

    return 0;
}
