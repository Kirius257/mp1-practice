#include "Pair.h"
#include <string>

using namespace std;

Pair::Pair(void) :num(0), product(nullptr) {}

Pair::Pair(int num_, long code_, string name_, double cost_) {
	num = num_;
	product = new TProduct(code_, name_, cost_);
}

Pair::Pair(const Pair& obj) {
	num = obj.num;
	product = new TProduct(*(obj.product));
}

Pair::~Pair() {
	if (product != nullptr) {
		delete product;
		product = nullptr;
	}
}


