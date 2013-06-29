/*
 * example_numeric.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: mvis
 */

namespace example_numeric {

void example_accumulate() {
	const int len = 8;
	int array[len] = { 4, 12, 3, 6, 10, 7, 8, 5 };
	int sum = 0;
	sum = accumulate(array, array + len, sum);
	cout << __PRETTY_FUNCTION__ << "\n\tSum of all elements: " << sum;
	cout << "1000 + a[2] + a[3] + a[4] = "
			<< accumulate(array + 2, array + 5, 1000);
	cout << endl;
}

void example_accumulate_prod_predicate() {
	const int len = 3;
	int array[len] = { 4, 12, 3 };
	int mult = 1;
	mult = accumulate(array, array + len, mult, multiplies<int>());
	cout << __PRETTY_FUNCTION__ << "\n\tMultiplication of all elements: "
			<< mult;
	cout << endl;
}

class COperation {
public:
	COperation() {
		i = 1;
	}
	int operator()(int x, int y) {
		int result = x + i * y;
		i = i << 1;
		return result;
	}
private:
	int i;
};

void example_accumulate_prod_fobj() {
	const int len = 3;
	int array[len] = { 4, 12, 3 };
	int mult = 1;
	mult = accumulate(array, array + len, mult, COperation());
	cout << __PRETTY_FUNCTION__ << "\n\tMultiplication of all elements: "
			<< mult;
	cout << endl;
}

}

