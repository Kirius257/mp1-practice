#pragma once
#ifndef TRECIPLINE_H
#define TRECIPLINE_H
#include "TProduct.h"



struct TRecipline {
	int num;
	double sum;
	TProduct product;

	TRecipline(void);
	TRecipline(int num_,TProduct product_) ;
	TRecipline(const TRecipline& obj);
	
	TRecipline& operator=(const TRecipline& obj);
	bool operator==(const TRecipline& obj);
	
};

ostream& operator<<(ostream& stream, const TRecipline& triple);
#endif