#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

#define PI 3.14159265358979323846

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	double a,b,d; cin >> a >> b >> d; // a=cos b=sin
	if(a==0 && b==0) {
		cout << "0.0 0.0\n";
		return 0;
	}
	double angle;
	if(a==0 && b>0) angle = 90;
	else if(a==0 && b>0) angle = 270;
	else angle = atan(abs(b/a))*180/PI;

	if(a<0 && b>=0) angle = 180-angle;
	else if(a<0 && b<0) angle+=180;
	else if(a>0 && b<0) angle = 360-angle;

	angle=atan2(b,a)*180/PI;

	double h = sqrt(a*a+b*b);

	print(h,angle);
	cout << std::fixed << setprecision(10) << cos((angle+d)*PI/180)*h << ' ' << sin((angle+d)*PI/180)*h << endl;
}
