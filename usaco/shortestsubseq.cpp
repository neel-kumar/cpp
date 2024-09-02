// find blocks of all characters
// once you identify all blocks, choose last char in each block 
// to choose the last character make sure that you don't choose any characters after the chosen block(Ex: acgt[c])

#include <iostream>
#include <set>

using namespace std;

string in;

int main() {
    cin >> in;
    string ans = "";
    set<char> curb;
    for(char i : in) {
        curb.insert(i);
        if(curb.size() == 4) {
            ans += i;
            curb.clear();
        }
    }
    for(char i : {'A', 'C', 'G', 'T'}) {
        if(curb.count(i) == 0) {
            cout << (ans + i);
            return 0;
        }
    }

    return 0;
}
