#include <map>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>& find_adj(map<int, vector<int> >& graph, int n, vector<int>& adjn, int level) {
	if(level > 0) {
		return adjn;
	} else {
		for(int an : graph[n]) {
			adjn.push_back(an);
			adjn = find_adj(graph, an, adjn, level+1);
		}
		return adjn;
	}
}

int main() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	int nnodes;
	cin >> nnodes;
	map<int, vector<int> > graph;
	for(int i = 1; i < nnodes; i++) {
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

	// map<int, set<int> > adjns;
	unsigned long int ans = 0;
	for(int i = 1; i <= nnodes; i++) {
		/*
		vector<int> adjn1;
		vector<int> adjn2;
		if(find_adj(graph, i, adjn1, 0).size() > ans) {
			ans = find_adj(graph, i, adjn2, 0).size();
		}*/

		if(graph[i].size() > ans) {
			ans = graph[i].size();
		}
	}
	cout << ans+1;
	return 0;
}

