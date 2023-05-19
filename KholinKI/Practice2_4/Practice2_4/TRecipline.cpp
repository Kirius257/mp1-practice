#include "TRecipline.h"







TRecipline::TRecipline(void) {
	num = 0;
	sum = 0;
	product = nullptr;
}

TRecipline::TRecipline(TProduct product_,int num_, long code_, std::string name_, double cost_) {
	num = num_;
	product = product_;
}

TRecipline::TRecipline(const TRecipline& obj) {
	num = obj.num;
	product = obj.product;
}

