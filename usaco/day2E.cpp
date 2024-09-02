#include <bits/stdc++.h>
using namespace std;

int main(){
	long t; cin >> t;
	for(long i = 0; i < t; i++){
		long long ans = 0;
		long long n, k; cin >> n >> k;
		map<long long , long long> a;
		long long x;
		for(long long j = 0; j < n; j++){
			cin >> x;
			if(x % k){
				a[k - (x % k)]+=1;
			}
		}
		bool tru = false;
		for(auto it:a){
			tru = true;
			ans = max(ans, (k * (it.second-1)) + it.first);
		}
		if(tru){ ans++; }
		cout<<ans<<endl;

	}
}
