/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second

signed main() {
  /* ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); */
  /* freopen("meetings.in", "r", stdin); */
  /* freopen("meetings.out", "w", stdout); */

  int n, l;
  cin >> n >> l;
  map<int, int> d;
  vector<pi> cws;
  int target = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    d[b] = (c == 1);
    target += a;
    cws.push_back({b, a});
  }

  sort(cws.begin(), cws.end());
  map<int, int> w;
  int c = cws[0].s;
  for (pi i : cws) {
    if (!d[i.f]) {
      w[i.f] = c;
      c = i.s;
    }
  }

  reverse(cws.begin(), cws.end());
  c = cws[0].s;
  bool prev = 0;
  for (pi i : cws) {
    if (d[i.f]) {
      if (prev)
        c = i.s;
      w[i.f] = c;
      if (!prev)
        c = i.s;
    }
    prev = d[i.f];
  }

  reverse(cws.begin(), cws.end());
  target = (target + 1) / 2;
  int col = 0, sum = 0;
  int lo = 0, hi = n - 1;
  int clo = 0, chi = 0;

  /* int cnt=0; */
  /* for(pi i : cws) { */
  /* 	printf("%lld %lld %lld\n", i.f, w[i.f], cnt); */
  /* 	cnt++; */
  /* } */

  while (sum < target) {
    if (cws[lo].s < (n - 1 + cws[hi].s) && lo < n) {
      // lo stuff
      if (!d[cws[lo].f]) {
        col += clo;
        sum += w[cws[lo].f];
      } else if (lo < hi) {
        clo++;
      }
      lo++;
    } else {
      // hi stuff
      if (d[cws[hi].f]) {
        col += chi;
        sum += w[cws[hi].f];
      } else if (lo < hi) {
        chi++;
      }
      hi--;
    }

    /* if(lo <= n && hi >= 0) */
    /* 	printf("%lld %lld SUM: %lld COL: %lld\n", lo, hi, sum, col); */
  }

  printf("%lld\n", col);
}
