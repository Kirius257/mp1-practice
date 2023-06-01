#include "TRecipline.h"
#include <iomanip>


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
	sum = obj.sum;
	product = obj.product;
}

TRecipline& TRecipline::operator=(const TRecipline& obj) {
	num = obj.num;
	sum = obj.sum;
	product = obj.product;
	return *this;
}

bool TRecipline::operator==(const TRecipline& obj) {
		if (product == obj.product) {
			return true;
		}
		else return false;
}



ostream& operator<<(ostream& stream, const TRecipline& triple) {
	stream << left << triple.product
		   << setw(20) << triple.num
		   << setw(20) << triple.sum;
	stream << endl;
	return stream;
}