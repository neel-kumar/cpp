#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> d;

int main() {
    ifstream fin("diamond.in");
    //ifstream tin(".txt");
    ofstream fout("diamond.out");

    fin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a; fin >> a;
        d.push_back(a);
    }
    sort(d.begin(), d.end());

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (d[j] - d[i] <= k)
                ans = max(ans, j - i + 1);
    fout << ans << endl;

    /*int ans = 0;
      for(int i = 0; i < n; i++) {
      int c = 0;
      for(int j = 0; j < n; j++) {
      if(abs(d[i]-d[j]) <= k) c++;
      }
      ans = max(ans, c);
      }
      cout << ans << endl;*/
}
