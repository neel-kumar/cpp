#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
using ld = long double;
using ll = long long;

ll N, M, K;

bool works2(ll x) {
    ll k = 0;
    ll gn = N;

    for(k = 0; k < K && gn >= 0; k++) {
        ll y = max((gn)/x, M);
        if(y == M)
            return (gn) <= M*(K-k);
        gn -= y;
    }

    return gn <= 0;
}

bool works(ll x) {
    ll k = K;
    ll gn = N;

    while(k > 0 && gn > 0) {
        ll y = max((gn)/x, M);
        if(y == M)
            return (gn) <= M*(k);
        ll sub = (gn-(x*y))/y + 1;

        sub = min(sub, k);

        gn -= y*(sub); 
        k -= sub; 
    }

    return gn <= 0;
}

ll last_true(ll lo, ll hi, function<bool(ll)> f) {

	lo--;

	for (ll dif = hi - lo; dif > 0; dif /= 2) {

		while (lo + dif <= hi && f(lo + dif)) {

			lo += dif;

		}

	}

	return lo;

}

int main() {
    ifstream fin("loan.in");
    //ifstream tin(".txt");
    ofstream fout("loan.out");

    fin >> N >> K >> M;

    fout << last_true(1, 1e12, works) << endl;
    // fout << last_true(1,1e12, valid) << endl;

    /*
    long long lhs = 1;
  long long rhs = 1e12;
  while(lhs < rhs) {
    long long mid = (lhs + rhs + 1) / 2;
    if(works(mid)) {
      lhs = mid;
    }
    else {
      rhs = mid - 1;
    }
  }
  fout << lhs << endl;
*/

    return 0;
}
