#include <iostream>
#include <vector>

using namespace std;

bool isprime(long long n) {
    if(n == 1) return false;;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;

	return true;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        long long sqrtx = sqrt(x);
        if(sqrtx*sqrtx == x && isprime(sqrtx)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
