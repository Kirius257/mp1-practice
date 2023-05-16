#pragma once
#ifndef PAIR_H
#define PAIR_H
#include "TProduct.h"
#include <string>

using namespace std;

 struct Pair {
	TProduct* product;
	int num;
 
	Pair(void);
	Pair(int num_, long code_, string name_, double cost_);
	Pair(const Pair& obj);
	~Pair();
};

#endif