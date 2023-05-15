#include "Pair.h"
#include <string>

using namespace std;

Pair::Pair(void) :num(0), product(nullptr) {}

Pair::Pair(int num_, long code_, string name_, double cost_) {
	num = num_;
	product = new TProduct(code_, name_, cost_);
}