namespace example_find {

bool example_find_if_cond(int x) {
	return (3 <= x) && (x <= 8);
}

class CCondObject {
public:
	bool operator()(int x) {
		return (3 <= x) && (x <= 8);
	}
};

void example_find_if() {
	list<int> my_list;
	//fill list with values
	my_list.push_back(10);
	my_list.push_back(7);
	my_list.push_back(4);
	my_list.push_back(1);
	list<int>::iterator i;
//	i = find_if(my_list.begin(), my_list.end(), example_find_if_cond);
	i = find_if(my_list.begin(), my_list.end(), CCondObject());
	if (i != my_list.end()) {
		cout << __PRETTY_FUNCTION__ << "\n\tfound element: " << *i << endl;
	}
}

}
