#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>

using namespace std;
#define int long long

int x;
int l, r;
int dp[18][180][2]; // last digit chosen, sum, 0/1 is the prefix equal to num;
int arr[18][2][162];


// make it recurse
// find num of ints from 0-limit with digit sum = x
int digi(string limit, int n, int xr, bool b) {
	if(xr < 0) return 0;
	if(n == 0 && xr == 0) return 1;
	if(n == 0) return 0;
	if(dp[n][xr][b] != -1) return dp[n][xr][b];
	int nxt = b ? (limit[limit.size()-n]-'0') : 9;
	//cout << limit << " " << n << " " << b << " " << nxt << " " << limit.size() << endl;
	int ans = 0;
	for(int i = 0; i <= nxt; i++) ans += digi(limit, n-1, xr-i, b&(i==nxt));
	//cout << "DIGI " << n << " " << xr << " " << b << " === " << ans << endl;
	return dp[n][xr][b] = ans;
}

int count_digits(int i, bool check, int temp, int total, string str, int size) {
	if (i == size) {
		if (temp == total) {
			return 1;
		} else {
			return 0;
		}
	}
	int count = arr[i][check][temp];
	if (count != -1) {
		return count;
	}
	count = 0;
	bool check_2;
	int temp_2;
	for (char ch = '0'; ch <= '9'; ch++) {
		if (!check) {
			if (ch > str[i]) {
				break;
			}
		}
		check_2 = check || ch < str[i];
		temp_2 = temp + (ch - '0');
		count += count_digits(i + 1, check_2, temp_2, total, str, size);
	}
	return count;
}

int driver(int start) {
	//cout << "driv\n";
	// char s[GetNumberOfDigits(start)];
	char s[100];
	// itoa(start, s, 10);
	sprintf(s, "%lld", start);
	string st = s; // "" + start;
	//cout << st.size() << " " << st << " " << start << endl;
	//return digi(st, st.size(), x, 1);
	return count_digits(0, 0, 0, x, st, st.size());
}

signed main() {
	cin >> l >> r >> x;
	for(int i = 0; i < 18; i++) for(int j = 0; j < 180; j++) for(int k = 0; k < 2; k++) dp[i][j][k] = -1;
	memset(arr, -1, sizeof(arr));
	int rans = driver(r);
	int lans = driver(l-1);
	//cout << "L: " << l-1 << " = " << lans << endl;
	//cout << "R: " << r << " = " << rans << endl;
	cout << rans-lans << endl;
	return 0;
}

