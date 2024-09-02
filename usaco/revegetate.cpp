#include <map>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("revegetate.in", "r", stdin);
	//freopen("revegetate.out", "w", stdout);
	int N, M;
	map<int, vector<int>> graph;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		if(graph.count(n1) == 0) {
			graph[n1] = {n2};
		} else {
			graph[n1].push_back(n2);
		}

		if(graph.count(n2) == 0) {
			graph[n2] = {n1};
		} else {
			graph[n2].push_back(n1);
		}
	}

	map<int, int> n2c;
	for(int n = 1; n < N+1; n++) {
		set<int> ac;
		for(int an : graph[n]) {
			if(n2c.count(an) != 0) {
				ac.insert(n2c[an]);
			}
		}
		for(int c = 1; c < 5; c++) {
			if(ac.count(c) == 0) {
			   n2c[n] = c;
			   break;
			}
		}
	}

	for(int i = 1; i < N+1; i++) {
		cout << n2c[i];
	}
	return 0;
}

