#include "Pair.h"
#include <string>

Pair::Pair(void) :num(0), product(nullptr){}

Pair::Pair(int num_, long code_, std::string name_, double cost_) {
	num = num_;
	product = new TProduct(code_, name_, cost_);
}