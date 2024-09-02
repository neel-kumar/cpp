#include <iostream>
#include <cstdio>
using namespace std;

bool is_covered(long long x, long long y, long long x1, long long y1, long long x2, long long y2, long long x3, 
		long long y3, long long x4, long long y4) {
	if((x >= x1 && x <= x2 && y >= y1 && y <= y2) || (x >= x3 && x <= x4 && y >= y3 && y <= y3)) {
		return true;
	} return false;
}

int main() {
	freopen("whitesheet.in", "r", stdin);
	long long wx1, wy1, wx2, wy2, b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2;
	cin >> wx1 >> wy1 >> wx2 >> wy2;
	cin >> b1x1 >> b1y1 >> b1x2 >> b1y2;
	//cout << wx1 << wy1 << wx2 << wy2;
    //cout << b1x1 << b1y1 << b1x2 << b1y2;

	if (is_covered(wx1, wy1, b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2) &&
		is_covered(wx1, wy2, b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2) && 
		is_covered(wx2, wy1, b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2) && 
		is_covered(wx2, wy2, b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2)) {
		cout << "NO";
	} else {
		cout << "YES";
	}
}
