#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 200043;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

int fact[N];

int C(int n, int k)
{
	return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	if(k > n - 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = mul(i, fact[i - 1]);
	int ans = 0;
	int c = n - k;
	for(int i = c; i >= 0; i--)
		if(i % 2 == c % 2)
			ans = add(ans, mul(binpow(i, n), C(c, i)));
		else
			ans = sub(ans, mul(binpow(i, n), C(c, i)));
	ans = mul(ans, C(n, c));
	if(k > 0)
		ans = mul(ans, 2);
	cout << ans << endl;
}
