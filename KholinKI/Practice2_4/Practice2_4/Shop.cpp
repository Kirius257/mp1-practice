#include "Shop.h"

Shop::Shop() {
	num_checks = 0;
}

void Shop::add(const TReceipt& check) {
	checks.push_back(check);
	num_checks++;
}

ostream& operator<<(ostream& stream, const Shop& obj) {
	stream << obj.checks;
	return stream;
}