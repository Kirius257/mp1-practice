#include <iostream>
#include <string>
#include "TReceipt.h"


using namespace std;




TRecipline::TRecipline(void) {
	num = 0;
	sum = 0;
	product = nullptr;
}

TProduct::TProduct(void) {
	code = 0;
	name = "";
	cost = 0.0;
}

TReceipt::TReceipt(int num_c,const string& path) {
	//#Creating containers
	num_conts = num_c;
	products = new TContainer *[num_conts];
	for (int i = 0; i < num_conts; i++) {
		products[i] = new TContainer();
	}
	
//#create product base
	products[0]->get_data_base(path,index);
}


TContainer::TContainer(int max_size = 100, int step = 10) {
		this->max_size = max_size;
		this->step = step;
		element = new elements*[this->max_size];
}

TProduct::TProduct(long code_, std::string name_, double cost_) {
	code = code_;
	name = name_;
	cost = cost_;
}

TRecipline::TRecipline(int num_) {
	num = num_;
}



