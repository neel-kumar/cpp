#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

void hello() {
	cout << "Hello World!" << endl;
}

void helloi(int i) {
    i = -1;
    cout << "helloi " << i << endl;
}

void hellor(int &i) {
    i = -1;
    cout << "hellor " << i << endl;
}

int main(void) {
#ifdef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

	std::cout << "Hello World!" << endl;
	std::cout << "Epic Gamer" << endl;
	cout << "Input a number: " << endl;

	hello();

    int i = 4;
    cout << "before " << i << endl;
    helloi(i);
    cout << "after helloi " << i << endl; // 4
    cout << endl;

    int j = 4;
    cout << "before " << j << endl;
    hellor(j);
    cout << "after hellor " << j << endl; // -1
    cout << endl;

    int x;
    cout << x << endl;

    int y;
    cout << y << endl;

	return 0;
}

