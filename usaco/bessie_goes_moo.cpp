/*
ID: n27k
TASK: task
LANG: C++
http://www.usaco.org/index.php?page=viewproblem2&cpid=549
*/

#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ifstream fin("bgm.in");
    //ifstream tin(".txt");
    ofstream fout("bgm.out");

    int n; fin >> n;
    vector<vll> vvi(10, vll(10, 0));
    // B is 0,   E is 1,   S is 2,   I is 3,   G is 4,   O is 5,   M is 6
    for (int i = 0; i < n; i++)
    {
        char ch; int num; fin >> ch >> num;
        if (ch == 'B') vvi[0][(num % 7 + 7) % 7]++;
        else if (ch == 'E') vvi[1][(num % 7 + 7) % 7]++;
        else if (ch == 'S') vvi[2][(num % 7 + 7) % 7]++;
        else if (ch == 'I') vvi[3][(num % 7 + 7) % 7]++;
        else if (ch == 'G') vvi[4][(num % 7 + 7) % 7]++;
        else if (ch == 'O') vvi[5][(num % 7 + 7) % 7]++;
        else                vvi[6][(num % 7 + 7) % 7]++; // M
    }

    ll count = 0;
    for (int b = 0; b < 7; b++)
        for (int e = 0; e < 7; e++)
            for (int s = 0; s < 7; s++)
                for (int i = 0; i < 7; i++)
                    for (int g = 0; g < 7; g++)
                        for (int o = 0; o < 7; o++)
                            for (int m = 0; m < 7; m++)
                                if (((b+e+s+s+i+e)*(g+o+e+s)*(m+o+o)) % 7 == 0)
                                    count += vvi[0][b] * vvi[1][e] * vvi[2][s] * vvi[3][i] * vvi[4][g] * vvi[5][o] * vvi[6][m];

    fout << count << endl;

    return 0;
}
