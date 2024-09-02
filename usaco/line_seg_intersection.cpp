#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

// if collinear
// does b lie on line(a,c)
bool on_seg(ii a, ii b, ii c) {
	if (b.first <= max(a.first, c.first) && b.first >= min(a.first, c.first) &&
		b.second <= max(a.second, c.second) && b.second >= min(a.second, c.second))
		return true;
	else
		return false;
}

// 0-collinear, 1=clockwise, 2=counterclockwise
int orient(ii a, ii b, ii c) {
	int val = (b.second - a.second) * (c.first - b.first) -
			   (b.first - a.first) * (c.second - b.second);
	if(val == 0) return 0;
	return (val > 0)?1:2;
}

bool intersect(ii a1, ii b1, ii a2, ii b2) {
	int o1 = orient(a1, b1, a2);
	int o2 = orient(a1, b1, b2);
	int o3 = orient(a2, b2, a1);
	int o4 = orient(a2, b2, b1);

	if(o1 != o2 && o3 != o4) return true;

	if(o1 == 0 && on_seg(a1, a2, b1)) return true;
	if(o2 == 0 && on_seg(a1, b2, b1)) return true;
	if(o3 == 0 && on_seg(a2, a1, b2)) return true;
	if(o4 == 0 && on_seg(a2, b1, b2)) return true;

	return false;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ii a, b, c, d;
		scanf("%d %d %d %d %d %d %d %d", &a.first , &a.second , &b.first , &b.second , &c.first , &c.second , &d.first , &d.second);
		if(intersect(a, b, c, d)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
