#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++){
      cin >> arr[i];
    }
    int binary_arr[n][31];
    for (int i = 0; i < n; i++){
      for (int j = 0; j < 31; j++){
        binary_arr[i][j] = 0;
        if (pow(2, 30-j) <= arr[i]){
          binary_arr[i][j] = 1;
          arr[i] -= pow(2, 30-j);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < 31; i++){
      int zeroes = 0;
      for (int j = 0; j < n; j++){
        if (binary_arr[j][i] == 0){
          zeroes++;
        }
      }
      if (k >= zeroes){
        k -= zeroes;
        ans += pow(2, 30-i);
      }
    }
    cout << ans << endl;
  }
}
