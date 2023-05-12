#pragma once
#ifndef TRECIPLINE_H
#define TRECIPLINE_H
#include "TProduct.h"

struct TRecipline {
	int num;
	double sum;
	TProduct* product;

	TRecipline(void);
	TRecipline(const TRecipline& obj);
};
#endif