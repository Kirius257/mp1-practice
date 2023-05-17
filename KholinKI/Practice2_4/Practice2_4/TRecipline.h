#pragma once
#ifndef TRECIPLINE_H
#define TRECIPLINE_H
#include "TProduct.h"



struct TRecipline {
	int num;
	double sum;
	TProduct* product;

	TRecipline(void);
	TRecipline(int num_, long code_, std::string name_, double cost_);
	TRecipline(const TRecipline& obj);
	~TRecipline();


};

#endif