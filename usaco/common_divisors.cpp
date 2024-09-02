#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int N, divisors[MAX+1];

int main() {
	scanf("%d", &N);
	divisors[1] = INT_MAX;
	int max_input = 0;
	for(int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		max_input = max(max_input, x);
		divisors[x]++;
		for(int i = 2; i <= (int)sqrt(x); i++) {
			if(x%i == 0) {
				divisors[i]++;
				if(i != (int)x/i) divisors[x/i]++;
			}
		}
	}

	for(int i = max_input; i >= 1; i--) {
		printf("DIV%d #%d\n", i, divisors[i]);
		if(divisors[i] > 1) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("1\n");

	return 0;
}
