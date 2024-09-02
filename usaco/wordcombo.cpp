#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7; //1000000007;
string in;
int memo[5001];
int k, n;
int trie[1000001][26];
bool isword[1000001];
int tc = 1;

void insert(string s) {
    int ss = s.size();
    int node = 0;
    for(int i = 0; i < ss; i++) {
        if(trie[node][s[i]-'a'] == 0) {
            trie[node][s[i]-'a'] = tc;
            tc++;
        }
        node = trie[node][s[i]-'a'];
    }
    isword[node] = true;
}

int main() {
    cin >> in >> k;
    n = in.size();
    for(int i = 0; i < k; i++) {
        string x;
        cin >> x;
        insert(x);
    }

    memo[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        string c = "";
        int node = 0;
        long long ans = 0;
        for(int j = i; j < n; j++) {
            c += in[j];
            if(trie[node][in[j]-'a'] != 0) {
                node = trie[node][in[j]-'a'];
            } else break;
            if(isword[node]) {
                ans += memo[j+1] % m;
                ans = ans % m;
            }
        }
        memo[i] = ans;
    }

    cout << memo[0];

    return 0;
}
