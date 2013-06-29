/*
 * example_remove.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: mvis
 */

namespace example_remove {

void out(const char* str, const vector<int> &v) {
	cout << str;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}
vector<int> fill_vector() {
	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	return v;
}

void remove_elems() {
	vector<int> v = fill_vector();
	vector<int>::iterator new_end;

	cout << __PRETTY_FUNCTION__;
	out("\n\tInitial sequence: ", v);
	new_end = remove(v.begin(), v.end(), 1);
	out("\n\tAfter remove from beign to end: ", v);
	cout << "\n\tAfter remove from beign to new_end: ";
	copy(v.begin(), new_end, ostream_iterator<int>(cout, " "));
	v.erase(new_end, v.end());
	out("\n\tAfter erase: ", v);
	cout << endl;
}

bool cond(int x) {
	return x <= 2;
}

void remove_if_elems() {
	vector<int> v = fill_vector();
	vector<int>::iterator new_end;
	cout << __PRETTY_FUNCTION__;
	out("\n\tInitial sequence: ", v);
	new_end = remove_if(v.begin(), v.end(), cond);
	v.erase(new_end, v.end());
	out("\n\tAfter erase: ", v);
	cout << endl;
}

}

