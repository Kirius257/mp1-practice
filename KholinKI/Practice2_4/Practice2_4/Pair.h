#pragma once
#ifndef _PAIR_H
#define _PAIR_H
#include "TProduct.h"
#include <string>

using namespace std;

struct Pair {
	TProduct* product;
	int num;

	Pair(void);
	Pair(int num_, long code_, string name_, double cost_);
};

#endif