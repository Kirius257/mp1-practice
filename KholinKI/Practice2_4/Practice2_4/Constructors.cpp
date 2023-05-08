#include <iostream>
#include <string>
#include "TReceipt.h"


using namespace std;

TReceipt::TReceipt(void) {
	index = 0;
	date = nullptr;
	time = nullptr;
	products = nullptr;
}

TContainer::TContainer(void) {
	count = 0;
	element = nullptr;
	max_size = 0;
	step = 0;
}

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

	//#Product base container
	products[0] = new TContainer(path);//a starting point for the creation of a product base

	//#General container
	//products[1] = new TContainer()
}


TContainer::TContainer(int max_size, int step) {
		this->max_size = max_size;
		this->step = step;
		element = new elements*[this->max_size];
}

TContainer::TContainer(const string& path) {
	try {
		ifstream file(path);
		if (file.is_open() == 0) {
			FileExeption ex = FileExeption::NullPtrFile;//get access ::
			throw ex;
		}
		file >> count;
		element = new elements*[count];
		
		string name_;
		double cost_;
		int num_;
		long code_;
		for (int i = 0; i < count; i++) {
			file >> num_ >> code_ >> name_ >> cost_;
			element[i] = new TRecipline(num_, code_, name_, cost_);
		}
		file.close();
	}
	catch (FileExeption ex) {
		cout << "Check that the file path is correct! Programm is over with code " << static_cast<int>(ex) << endl;
	}
}

TRecipline::TRecipline(int num_, long code_, string name_, double cost_) {
	this->num = num_;
	product = new TProduct();
	product->code = code_;
	product->name = name_;
	product->cost = cost_;
}

