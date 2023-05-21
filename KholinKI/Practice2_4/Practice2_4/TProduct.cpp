#include "TProduct.h"

TProduct::TProduct(void) {
	code = 0;
	name = "";
	cost = 0.0;
}



TProduct::TProduct(long code_, std::string name_, double cost_) {
	code = code_;
	name = name_;
	cost = cost_;
}


TProduct::TProduct(const TProduct& obj) {
	code = obj.code;
	name = obj.name;
	cost = obj.cost;
}


bool TProduct::operator==(const TProduct& obj) {
	if (code == obj.code) {
		return true;
	}
	else return false;
}

