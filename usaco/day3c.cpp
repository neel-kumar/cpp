#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
string str;

int recur(char level, int l, int r){
    int m = (l+r)/2;
    if (l == r){
        return (str[l] != level);
    }
    int moves1 = 0;
    int moves2 = 0;
    for (int i = l; i <= m; i++){
        if (level != str[i]){
            moves1++;
        }
    }
    for (int i = m+1; i <= r; i++){
        if (level != str[i]){
            moves2++;
        }
    }
    moves1 += recur(level+1, m+1, r);
    moves2 += recur(level+1, l, m);
    return min(moves1, moves2);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cin >> str;
        cout << recur('a', 0, n-1) << "\n";
    }
}
