#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	freopen("whereami.in", "r", stdin);
	
	int n; string mb;
	cin >> n;
	cin >> mb;
	string seq;
	bool isrep;

	for(int i = 1; i < n; i++) {
		seq = mb.substr(0, i);
		isrep = false;

		for(int j = i+1; j < n; j++) {
			if (seq == mb.substr(j, i)) {
				isrep = true;
				break;
			}
		}
		if (!isrep) {
			cout << i;
			break;
		}
	}
}
