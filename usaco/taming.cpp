#include <map>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("taming.in", "r", stdin);
	//freopen("taming.out", "w", stdout);
	int N, min, max;
	vector<int> log;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int l;
		cin >> l;
		log.push_back(l);
	}

	min = 0;
	max = 0;
	int i = N-1;

	while(i > 0) {
		if(log[i] != -1) {
			int dif = 1;
			for(int j = i-1; j >= i-log[i]; j--) {
				if(log[j] == log[i]-dif || log[j] == -1) {
					dif++;
				} else {
					cout << "-1";
					return 0;
				}
			}
			i -= log[i] + 1;
			min++;
			max++;
		} else {
			max++;
			i--;
		}
	}
	if(i == 0) {
		cout << min+1 << " " << max+1;
	} else {
		cout << min << " " << max;
	}
	
	return 0;
}

