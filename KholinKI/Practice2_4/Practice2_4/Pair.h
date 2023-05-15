#pragma once
#ifndef _PAIR_H
#define _PAIR_H
#include "TProduct.h"

struct Pair {
	TProduct* product;
	int num;

	Pair(int _num, const TProduct& obj);
};

#endif