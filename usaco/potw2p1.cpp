#include <bits/stdc++.h>
using namespace std;

bool P(int number) {
  string str = to_string(number);
  for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

int main() {
	int ans = 0;
	for(int i = 100; i < 1000; i++) {
		for(int j = 100; j < 1000; j++) {
			if(P(i*j)) ans = max(ans, i*j);
		}
	}
	cout << ans << endl;
}
