#pragma once
#ifndef _PAIR_H
#define _PAIR_H
#include "TProduct.h"

struct Pair {
	TProduct* product;
	int num;
	
	Pair(void);
	Pair(int num_,long code_,std::string name_,double cost_);
};

#endif