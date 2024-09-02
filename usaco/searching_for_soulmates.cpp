#include <bits/stdc++.h>

using namespace std;

long long cow1, cow2;

int main() {
	long long T; cin >> T;
	while(T--) {
		cin >> cow1 >> cow2;
		long long answer = INT_MAX;
		long long steps = 0, i = cow2;
		while(i > 1) {
			long long curr = cow1, add_steps = 0;
			while(curr > i) {
				if(curr % 2 == 1) {
					curr++;
					add_steps++;
				}
				curr /= 2;
				add_steps++;
			}
			add_steps += i-curr;
			//prlong longf("(S%d, A%d, I%d, ANS%d)\n", steps, add_steps, i, answer);
			answer = min(steps + add_steps, answer);
			if(i%2 == 1) {
				i--;
				steps++;
			}
			i /= 2;
			steps++;
		}
		if(answer == INT_MAX) answer = 0;
		cout << answer << endl;
	}
	
	return 0;
}
