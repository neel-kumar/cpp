#include <bits/stdc++.h>
using namespace std;

long long n, k, tree[1001][2], pindex[1001];
bool visited[1001][1001];
long long memo[1001][1001];

long long dfs(long long n, long long l) {
    if(visited[n][l])
        return memo[n][l];
    else if(l == 0)
        return 0;
    else if(n == 0)
        return INT64_MIN;
    else if(l == 1)
        return pindex[n];

    long long ans = INT64_MIN;
    for(long long i = 0; i < l; i++) {
        ans = max(ans, pindex[n] + dfs(tree[n][0], i) + dfs(tree[n][1], l-i-1));
    }
    visited[n][l] = true;
    return memo[n][l] = ans;
}

int main() {
    cin >> n >> k;
    for(long long i = 2; i <= n; i++) {
        cin >> pindex[i];
    }
    for(long long i = 1; i <= n; i++) {
        cin >> tree[i][0] >> tree[i][1];
    }

    cout << dfs(1, k+1);

    return 0;
}
