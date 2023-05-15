#include "TRecipline.h"




TRecipline::TRecipline(const TRecipline& obj) {
	num = obj.num;
	product = new TProduct(*(obj.product));
}


TRecipline::TRecipline(void) {
	num = 0;
	sum = 0;
	product = nullptr;
}