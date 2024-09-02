#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string dna;

int main() {
    cin >> dna;
    int ans=1, crep=0;
    char p=dna[0];
    for(char i : dna) {
        if(i == p) {
            crep++;
        } else {
            ans = max(ans, crep);
            crep = 1;
        }
        p = i;
    }
    ans = max(ans, crep);
    cout << ans;
    
    return 0;
}
