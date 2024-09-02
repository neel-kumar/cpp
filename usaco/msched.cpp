#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> time_milk;

int main() {
    ifstream fin("msched.in");
    ofstream fout("msched.out");
    fin >> n;

    int dLimit = 10000;
    int maxD = 0;
    vector<vector<int>> input(dLimit + 1, vector<int>());
    for (int i = 0; i < n; i++) {
      int g, d; fin >> g >> d;
      input[d].push_back(g);
      maxD = max(maxD, d);
    }
    for (int i = 0; i < dLimit; i++) sort(input[i].rbegin(), input[i].rend());

    int totalG = 0;
    for (int time = maxD - 1; time >= 0; time--) {
      int maxG = 0, indexJ = -1;
      for (int j = time + 1; j <= maxD; j++)
        if (input[j].size() >= 1 && input[j][0] > maxG)
          maxG = input[j][0], indexJ = j;
      if (indexJ != -1) totalG += maxG, input[indexJ].erase(input[indexJ].begin());
    }
    fout << totalG << endl;

  
    /*for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        time_milk.push_back(make_pair(b, a));
    }
    sort(time_milk.begin(), time_milk.end());

    int m = 0, i = n-1, over = 0;
    while(i >= 0) {
        int t = time_milk[i].first, a = i, n = over;
        while(time_milk[i].first == t) {
            m += time_milk[i].second;
            n++;
            i--;
            if(i < 0) break;
        }

        if(t-time_milk[i].first >= n) continue;

        int b = i;
        while(time_milk[b].second > time_milk[i].second && (a-i) <= time_milk[b].first) {
            i--;
            m -= time_milk[i].second;
        }
        over += (a-i);
    }

    cout << m << "\n";

    return 0;*/
}
