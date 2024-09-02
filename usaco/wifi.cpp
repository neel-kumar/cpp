/*
ID: n27k
TASK: task
LANG: C++
*/

#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
using ld = long double;
using ll = long long;

const double inf = std::numeric_limits<double>::max(); // 99000000000.0;

int n;
double a, b;
vector<double> c;
vector<double> memo(4002, inf);

double f(int n) {
    if(memo[n] != inf) return memo[n];

    double m = inf; // a + b * ((c[n] - c[1])/2.0);
    for(int i = 0; i < n; i++) {
        m = min(m, f(i) + a + b * ((c[n] - c[i + 1])/2.0));
    }
    memo[n] = m;

    return m;
}

int main() {
    // cout << "inf: " << inf << endl;

    ifstream fin("wifi.in");
    //ifstream tin(".txt");
    ofstream fout("wifi.out");

    fin >> n >> a >> b;
    c.push_back(-1);
    for(int i = 0; i < n; i++) {
        double a; fin >> a;
        c.push_back(a);
    }

    sort(c.begin(), c.end());

    memo[0] = 0;

    fout << setprecision(9) << f(n);
    //int ans = f(n);
    //ans > (int)ans ? fout << fixed << (int)ans << ".5\n" : fout << fixed << (int)ans << endl;

    return 0;
}
