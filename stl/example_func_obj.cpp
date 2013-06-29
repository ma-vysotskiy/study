/*
 * example_func_obj.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: mvis
 */

namespace example_func_obj {

class compare {
public:
	int operator()(int x, int y) {
		return x > y;
	}
};

void example1() {
	compare v;
	cout << __PRETTY_FUNCTION__ << "\n\t" << v(2, 15) << ", ";
	cout << compare()(5, 3) << endl;
}

}

