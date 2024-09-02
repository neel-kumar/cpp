#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

const int N = 6;
const int PS = N*N - 1;

string in;
bool g[N][N];
int c = 0;
char d[4] = {'D', 'U', 'L', 'R'};
int ci[256] = {0};
pair<int, int> d2pos[4];

int counter = 0;

inline bool rightpath(int path, char d) {
    if(in.at(path) == '?') return true; 
    else if(in.at(path) == d) return true;
    else return false;
}

inline bool canmove(int x, int y) {
    if(!g[x][y] && x >= 0 && y >= 0 && x < N && y < N) return true;
    else return false;
}

inline bool iswall(int x, int y) {
    if(!canmove(x+d2pos[0].first,y+d2pos[0].second) && !canmove(x+d2pos[1].first,y+d2pos[1].second) && canmove(x+d2pos[2].first,y+d2pos[2].second) && canmove(x+d2pos[3].first,y+d2pos[3].second)) return true;
    else if(canmove(x+d2pos[0].first,y+d2pos[0].second) && canmove(x+d2pos[1].first,y+d2pos[1].second) && !canmove(x+d2pos[2].first,y+d2pos[2].second) && !canmove(x+d2pos[3].first,y+d2pos[3].second)) return true;
    else return false;
}

void solve(int x, int y, const int path) {
    try {
    counter++;
    if(counter % 100000 == 0) cout << "Solve called " << counter << endl;
    if(!(x == (N-1) && y == 0 && path != PS) && path <= PS) {
        g[x][y] = true;
        if(path == PS && x == (N - 1) && y == 0) c++;
        else if(path != PS && !iswall(x, y)) {
            cout << "in is :" << in << ":" << endl;
                cout << "Path: " << path << endl;
                cout << "char: " << in.at(path) << endl;
                cout << "ci: " << ci[in.at(path)] << endl;
            if(in.at(path) == '?') {
            for(int i = 0; i < 4; i++) {
                if(/*rightpath(path, d[i]) && */ canmove(x+d2pos[i].first,y+d2pos[i].second)) {
                    solve(x+d2pos[i].first, y+d2pos[i].second, path+1);
                }
            }
            } else {
                cout << "in is :" << in << ":" << endl;
                cout << "Path: " << path << endl;
                cout << "char: " << in.at(path) << endl;
                cout << "ci: " << ci[in.at(path)] << endl;
                solve(x+d2pos[ci[in.at(path)]].first, y+d2pos[ci[in.at(path)]].second, path+1);
            }
        }
        g[x][y] = false;
    }
    } catch(const out_of_range& r) {
        cout << "Exception caught " << endl; 
        cout << "in is :" << in << ":" << endl;
        cout << "path is " << path << endl;
        exit(1);
    }
}

int main() {
    ci[(int)'D'] = 0;
    ci[(int)'U'] = 1;
    ci[(int)'L'] = 2;
    ci[(int)'R'] = 3;
    d2pos[0] = make_pair(1, 0);
    d2pos[1] = make_pair(-1, 0);
    d2pos[2] = make_pair(0, -1);
    d2pos[3] = make_pair(0, 1);
    cin >> in;
    cout << "in is :" << in << ":" << endl;
    solve(0, 0, 0);
    cout << c << endl;
    cout << "Solve called " << counter << endl;
    // N = 6 - 44M, 25.5M
    return 0;
}
