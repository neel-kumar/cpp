#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int cs[26];

void prchar(char c, int n) {
    for(int i = 0; i < n; i++) cout << c;
}

int main() {
    string s;
    cin >> s;
    int mid = -1;
    vector<int> od;
    string ans = "";
    for(char i : s) cs[i-'A']++;
    for(int i = 0; i < 26; i++) {
        if(cs[i] == 0) continue;
        else if(cs[i] % 2 == 0) {
            od.push_back(i);
            ans += (i+'A')*cs[i];
        } else if (mid == -1){
            mid = i;
        } else {
            cout << " NO SOLUTION";
            return 0;
        }
    }

    for(int i : od) prchar(i+'A',cs[i]/2);
    prchar(mid+'A', cs[mid]);
    for(int i = od.size()-1; i >= 0; i--) prchar(od[i]+'A',cs[od[i]]/2);

    return 0;
}
