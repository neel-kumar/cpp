#include <map>
#include <iostream>

using namespace std;
int N;
map<string, int> db;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string x;
        cin >> x;
        if(db.count(x) == 0) {
            db[x] = 1;
            cout << "OK\n";
        } else {
            cout << x << db[x]++ << "\n";
        }
    }

    return 0;
}
