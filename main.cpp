#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

#include "example_find.cpp"
#include "example_func_obj.cpp"
#include "example_remove.cpp"


int main() {
	example_func_obj::example1();
	example_find::example_find_if();
	example_remove::remove_elems();
	example_remove::remove_if_elems();
	return 0;
}
