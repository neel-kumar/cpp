#include <bits/stdc++.h>
#define int long long
using namespace std;

unsigned int reverseBits(unsigned int num)
{
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++) {
        if ((num & (1 << i)))
            reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
    }
    return reverse_num;
}

void solve() {
	int n; cin>>n;
	int a[n];
	vector<int> v;
	int sum = 0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum += a[i];
		v.push_back(reverseBits(a[i]));
	}
	sort(v.begin(), v.end());

	cout << (sum-reverseBits(v[0])-reverseBits(v[n-1])+(reverseBits(v[0])^reverseBits(v[n-1])));
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
