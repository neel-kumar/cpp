#include <bits/stdc++.h>
using namespace std;

int mb[8] = {1, 2, 4, 7, 8, 11, 13, 14};

int main() {
	ifstream fin("moobuzz.in");
	ofstream fout("moobuzz.out");

	int n; fin >> n;
	n--;
	int c = (int) n/8;
	int r = n%8;
	fout << ( mb[r] + c*15 ) << endl;
}
