#pragma once
#ifndef _CHECKS_H
#define _CHECKS_H

#include "TReceipt.h"


class Shop {
	friend ostream& operator<<(ostream& stream, const Shop& obj);
private:
	TContainer<TReceipt> checks;
	int num_checks;
public:
	Shop(void);
	void add(const TReceipt& check);
	int get_num() { return num_checks; }
};
#endif