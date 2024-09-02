#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int r[n][n];
	int arr[n]; memset(arr, 0, sizeof(arr));
	for(int i = 0; i < n-1; i++) {
		for(int j = i; j < n; j++) { cin >> r[i][j]; }
		int val = arr[i]+r[i][i+1];
		bool works = true;
		for(int j = 0; j < i; j++) {
			int ma = arr[j], mi = arr[j];
			for(int k = j+1; k <= i; k++) ma = max(ma, arr[k]), mi = min(mi, arr[k]);
			ma = max(ma, val), mi = min(mi, val);
			if( (ma-mi) != r[j][i+1] ) works = false;
		}
		arr[i+1] = works ? val : arr[i]-r[i][i+1];
	}
	int temp; cin >> temp; assert(temp == 0);
	for(int i = 0; i < n; i++) { cout << arr[i]; if(i != n-1) cout << " "; }
}
