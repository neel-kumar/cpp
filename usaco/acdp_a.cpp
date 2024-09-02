#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n; cin >> n;
  int a[n],dp[n+1];
  for(int i=0;i<n;i++) {
    cin >> a[i];
    dp[i]=INT_MAX;
  }
  dp[0]=0;
  for(int i=0;i<n;i++) {
    dp[i+1]=min(dp[i]+abs(a[i+1]-a[i]), dp[i+1]);
    dp[i+2]=min(dp[i]+abs(a[i+2]-a[i]), dp[i+2]);
  }
  cout << dp[n-1] << endl;
}
