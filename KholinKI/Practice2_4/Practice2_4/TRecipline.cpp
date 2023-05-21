#include "TRecipline.h"







TRecipline::TRecipline(void) {
	num = 0;
	sum = 0;
}

TRecipline::TRecipline(int num_,TProduct product_) {
	num = num_;
	product = product_;
}

TRecipline::TRecipline(const TRecipline& obj) {
	num = obj.num;
	product = obj.product;
}

