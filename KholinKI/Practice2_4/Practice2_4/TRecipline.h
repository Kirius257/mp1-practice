#pragma once
#ifndef TRECIPLINE_H
#define TRECIPLINE_H
#include "TProduct.h"

class TRecipline {
public:
	int num;
	double sum;
	TProduct* product;//выделять под количество num?
};
#endif