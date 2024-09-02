#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double vx1 = (x3-x1), vy1 = (y3-y1), vx2 = (x2-x1), vy2 = (y2-y1);
        double z = (vx1*vy2) - (vx2*vy1);
        if(z == 0) cout << "TOUCH\n";
        else if(z < 0) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }

    return 0;
}
