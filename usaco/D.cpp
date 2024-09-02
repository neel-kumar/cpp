#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

void solve( int s ){
	int mat[ s ][ s ] = {0};
	int i, j, m, n, p, q, num;
	num = 1; // start count from 1
	i = 0;
	j = 0;
	m = 0; // row index lower limit
	n = s - 1; // row index upper limit
	p = 0; // column index lower limit
	q = s - 1; // column index upper limit
	while ( num <= s * s ) {

		// place numbers horizontally left to right
		for ( j = p; j <= q; j++ ) {
			mat[ m ][ j ] = num;
			num = num + 1;
		}
		m = m + 1;

		// fill vertically from top to bottom
		for ( i = m; i <= n; i++ ) {
			mat[ i ][ q ] = num;
			num = num + 1;
		}
		q = q - 1;

		// fill horizontally from right to left
		for ( j = q; j >= p; j-- ) {
			mat[ n ][ j ] = num;
			num = num + 1;
		}
		n = n - 1;

		// fill vertically from bottom to top
		for ( i = n; i >= m; i-- ) {
			mat[ i ][ p ] = num;
			num++;
		}
		p = p + 1;
	}

	// display the mat
	for ( i = 0; i < s; i++ ) {
		for ( j = 0; j < s; j++ ) {
			if(mat[i][j] == s*s)
				printf("T ");
			else
				printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int n; cin >> n;
	solve( n );

	return 0;
}
