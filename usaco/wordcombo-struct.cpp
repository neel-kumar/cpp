#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7; //1000000007;
string in;
int memo[5001];
int k, n;

struct tnode {
    bool isword;
    tnode* c[26];
    tnode(bool iw) {
        isword = iw;
        for(int i = 0; i < 26; i++) c[i] = 0;
    }
};

void insert(tnode* r, string s) {
    int ss = s.size();
    for(int i = 0; i < ss; i++) {
        if(r->c[s[i]-'a'] == 0) {
            tnode* newnode = new tnode(false);
            r->c[s[i]-'a'] = newnode;
        }
        r = r->c[s[i]-'a'];
    }
    r->isword = true;
}

int main() {
    cin >> in >> k;
    n = in.size();
    tnode* root = new tnode(false);
    for(int i = 0; i < k; i++) {
        string x;
        cin >> x;
        insert(root, x);
    }

    memo[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        string c = "";
        tnode* node = root;
        long long ans = 0;
        for(int j = i; j < n; j++) {
            c += in[j];
            if(node->c[in[j]-'a'] != 0) {
                node = node->c[in[j]-'a'];
            } else break;
            if(node->isword) {
                ans += memo[j+1] % m;
                ans = ans % m;
            }
        }
        memo[i] = ans;
    }

    cout << memo[0];

    return 0;
}
