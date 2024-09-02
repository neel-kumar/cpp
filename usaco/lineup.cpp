#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	freopen("lineup.in", "r", stdin);

	map<string, vector<string> > cm;

	vector<string> cows {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	sort(cows.begin(), cows.end());

	for(string c: cows) {
		cm[c] = vector<string>(); }
	int nc;
	string junk;
	cin >> nc;
	for(int i = 0; i < nc; i++) {
		string cow1;
		string cow2;
		cin >> cow1;
		for(int i = 0; i < 4; i++) {
			cin >> junk;
		}
		cin >> cow2;
		cm[cow1].push_back(cow2);
		cm[cow2].push_back(cow1);
	}

	set<string> pc;
	for(string c: cows) {
		if(cm[c].size() == 0 && pc.count(c) == 0) {
			pc.insert(c);
			cout << c << endl;
		} else if(cm[c].size() == 1 && pc.count(c) == 0) {
			cout << c << endl;
			string prev = c;
			string curr = cm[c][0];
			while(cm[curr].size() != 1) {
				pc.insert(curr);
				cout << curr << endl;
				if(cm[curr][0] == prev) {prev = curr; curr = cm[curr][1];}
				else {prev = curr; curr = cm[curr][0];}
			}
			pc.insert(curr);
			cout << curr << endl;
		}	
	}
	
	return 0;
}
