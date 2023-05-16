#include "TRecipline.h"







TRecipline::TRecipline(void) {
	num = 0;
	sum = 0;
	product = nullptr;
}

TRecipline::TRecipline(int num_, long code_, std::string name_, double cost_) {
	num = num_;
	product = new TProduct(code_, name_, cost_);
}

TRecipline::TRecipline(const TRecipline& obj) {
	num = obj.num;
	product = new TProduct(*(obj.product));
}

TRecipline::~TRecipline() {
	if (product != nullptr) {
		delete[] product;
		product = nullptr;
	}
}
