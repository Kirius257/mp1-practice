#pragma once
#ifndef TRECIPLINE_H
#define TRECIPLINE_H
#include "TProduct.h"

class TRecipline {
private:
	int num;
	double sum;
	TProduct* product;
public:
	TRecipline(void);
	TRecipline(int num_);

	bool check_end();
};
#endif