#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <vector>
#include <numeric>

using namespace std;

//lazy, i agree
#include "example_find.cpp"
#include "example_func_obj.cpp"
#include "example_remove.cpp"
#include "example_numeric.cpp"

int main() {
	example_func_obj::example1();
	example_find::example_find_if();
	example_remove::remove_elems();
	example_remove::remove_if_elems();
	example_numeric::example_accumulate();
	example_numeric::example_accumulate_prod_predicate();
	example_numeric::example_accumulate_prod_fobj();
	return 0;
}
