#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
#include <utility>
#include <climits>
#include <unordered_set>

using namespace std;

long long sm[10][2];
int N;

long long llby2 = LLONG_MAX/2;

bool ispof2(int N)
{
    if((N & 1) == 0) {
        // Iterate through all the bits
        int count1 = 0;
        while (N > 0) {
            // If current bit is 1
            if (N & 1) {
                count1++;
            }

            if(count1 > 1) break;

            N = N >> 1;
        }
        return count1 == 1;
    } else {
        return false;
    }
}

int main() {
    // freopen("sss.in", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        sm[i][0] = x;
        sm[i][1] = y;
    }

    for(int i = 0; i < N; i++) {
        long long p = sm[i][0];
        long long t = sm[i][1];
        unordered_set<long long> v;
        queue<tuple<long long, int, int> > q;
        q.push(make_tuple(p, 0, -1));
        v.insert(p);
        while(!q.empty()) {
            long long s;
            int c;
            int op;
            tie(s, c, op) = q.front();
            q.pop();

            if(s == t) {
                cout << c << endl;
                break;
            } else {
                long long tmp;
               
                if(op != 2) {
                tmp = s/2;
                if(s%2 == 0 && v.count(tmp) == 0) {
                    v.insert(tmp);
                    q.push(make_tuple(tmp, c+1, 1));
                }
                }

                if(op != 1) {
                tmp = s*2;
                if(s < t && s < llby2 && v.count(tmp) == 0) {
                    v.insert(tmp);
                    q.push(make_tuple(tmp, c+1, 2));
                }
                }

                {
                    // if target is reachable by successive *2 or /2, then +1 is not required.
                    bool addby1 = true;
                    if(t > s) {
                        if(t % s == 0 && ispof2(t/s))
                            addby1 = false;
                    } else {
                        if(s % t == 0 && ispof2(s/t))
                            addby1 = false;
                    }

                    if(addby1) {
                tmp = s + 1;
                if(v.count(tmp) == 0) {
                    v.insert(tmp);
                    q.push(make_tuple(tmp, c+1, 3));
                }
                    }
                }
            }
        }
    }

    return 0;
}

