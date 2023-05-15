#include <iostream>
#include <string>
#include "TReceipt.h"
#include "Pair.h"


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
		products[i] = new TContainer(3,10);
	}
	
//#create product base
	products[0]->get_data_base(path);
}


TContainer::TContainer(int max_size, int step) {
	pos = 0;
	count = 0,
	
	this->max_size = max_size;
	this->step = step;
		element = new elements[this->max_size];
}


TProduct::TProduct(long code_, std::string name_, double cost_) {
	code = code_;
	name = name_;
	cost = cost_;
}

Pair::Pair(int _num, const TProduct& obj) {
	num = _num;

}


TRecipline::TRecipline(const TRecipline& obj) {
	num = obj.num;
	product = new TProduct(*(obj.product));
}

TProduct::TProduct(const TProduct& obj) {
	code = obj.code;
	name = obj.name;
	cost = obj.cost;
}




