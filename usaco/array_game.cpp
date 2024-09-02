#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e8-3;

int merge(int* a, int left, int mid, int right, int s) {
    int cnt = 0;
    int i = left, j = mid+1, k = left;
	int b[s];
	memset(b, 0, s);
    while(i<=mid && j<=right) {
        if(a[i] <= a[j])    b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            cnt = (cnt + mid - i + 1) %mod;
        }
    }

    while(i <= mid) {
        b[k++] = a[i++];
    }
    while(j <= right) {
        b[k++] = a[j++];
    }

    for(i=left; i<=right; i++)  a[i] = b[i];
    return cnt;
}

int invCount(int* a, int left, int right, int s) {
    if(left >= right)   return 0;
    int mid = left + (right-left)/2;
    int cnt = (invCount(a, left, mid, s) + invCount(a, mid+1, right, s)) %mod;
    cnt = (cnt + merge(a, left, mid, right, s)) %mod;
    return cnt;
}


signed main() {
	int n; cin >> n;
	int a[n], b[n];
	pair<int, int> ta[n], tb[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ta[i].first = a[i];
		ta[i].second = i;
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		tb[i].first = b[i];
		tb[i].second = i;
	}

	sort(tb, tb+n); sort(ta, ta+n);
	// find how to swap pipe array into original
	for(int i = 0; i < n; i++) a[tb[i].second] = ta[i].second;
	cout << invCount(a, 0, n-1, n) << " ";

	// sort a&b to find cost
	int cost = 0;
	for(int i = 0; i < n; i++) cost = (cost+(tb[i].first-ta[i].first)*(tb[i].first-ta[i].first)) %mod;
	cout << cost << endl;
}
