#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

set<int>& dfs(map<int, vector<int> >& graph, int n, set<int>& vis) {
	vis.insert(n);
	for(int c : graph[n]) {
		if(vis.count(c) == 0) {
			// vis.insert(c);
			vis = dfs(graph, c, vis);
		}
	}
	return vis;
}

int main() {
	freopen("factory.in", "r", stdin);
	int ns;
	cin >> ns;
	map<int, vector<int> > graph;
	for(int i = 0; i < ns-1; i++) {
		int tail, head;
		cin >> head >> tail;
		if(graph.count(tail) == 0) {
			graph[tail] = {head};
		} else {
			graph[tail].push_back(head);
		}
	}
	for(int i = 1; i <= ns; i++) {
		set<int> vis;	
		if(dfs(graph, i, vis).size() == ns) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
	return 0;
}
