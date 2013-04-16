/*
 * example_count.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: mvis
 */

namespace example_count {

class CLetterE {
public:
	bool operator()(char c) {
		return c == 'e';
	}
};

void example_count_if() {
	const char *p = "This demonstrates the Standard Template Library";
	int n = count_if(p, p + strlen(p), CLetterE());
	cout << __PRETTY_FUNCTION__ << "\n\t found " << n << " letters 'e'";
	cout << endl;
}

}

