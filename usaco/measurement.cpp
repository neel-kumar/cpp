#include <map>
#include <iostream>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxc(int l[3]) {
	vector<int> maxs = {0};
	for(int i = 1; i < 3; i++) {
		if (l[maxs[0]] < l[i]) {
			maxs = {i};
		} else if (l[maxs[0]] == l[i]) {
			maxs.push_back(i);
		}
	}
	return maxs;
}


int main() {
	freopen("measurement.in", "r", stdin);
	//freopen("measurement.out", "w", stdout);
	int N;
	map<int, vector<pair<string, int>>> logs;
	cin >> N;
	int md = 0;
	for(int i = 0; i < N; i++) {
		int day, log;
		string cow;
		cin >> day >> cow >> log;
		logs[day].push_back(make_pair(cow, log));
		if (day > md) {
			md = day;
		}
	}
	vector<string> cows = {"Bessie", "Elsie", "Mildred"};
	map<string, int> cm;
	cm["Bessie"] = 7;
	cm["Elsie"] = 7;
	cm["Mildred"] = 7;
	int cc = 0;
	int pd[3] = {7,7,7};
	for(int i = 1; i <= md; i++) {
		//cout << cm["Bessie"] << " " << cm["Elsie"] << " " << cm["Mildred"] << endl;
		if(logs.count(i) == 0) {
			continue;
		} else {
			for(pair<string, int> log : logs[i]) {
				cm[log.first] += log.second;
			}
			
			int td[3] = {cm["Bessie"], cm["Elsie"], cm["Mildred"]};
			if(maxc(pd) != maxc(td)) {
				//cout << "DIFF" << endl;
				cc++;
			}
			pd[0] = td[0]; pd[1] = td[1]; pd[2] = td[2];
		}
	}
	cout << cc;
	return 0;
}

