#include <iostream>
#define N 8
using namespace std;

int n = 0;
int board[N][N];
bool d1[2*N-1];
bool d2[2*N-1];
bool column[N];

void solve(int l) {
    if(l == N) n++;
    else {
        for(int i = 0; i < N; i++) {
            if(column[i] || board[l][i] != 0 || d1[l+i] || d2[i-l+N-1]) continue;
            column[i] = d1[l+i] = d2[i-l+N-1] = 1;
            solve(l+1);
            column[i] = d1[l+i] = d2[i-l+N-1] = 0;
        }
    }
}

int main() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
        char x;
        cin >> x;
        if(x == '.')
            board[i][j] = 0;
        else
            board[i][j] = -1;
        }
    }

    solve(0);

    cout << n;

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

