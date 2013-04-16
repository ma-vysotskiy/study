#include <iostream>

using namespace std;

class compare {
public:
	int operator()(int x, int y) {
		return x > y;
	}
};

void example1() {
	compare v;
	cout << v(2, 15) << endl;
	cout << compare()(5, 3) << endl;
}

int main() {
	example1();
	return 0;
}
