#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H
#include "Container.h"
#include "TRecipline.h"
#include "Base.h"


class TReceipt {
	
private:
	TM DataTime;
	TContainer<TRecipline> products;
	void CLOCK();
	int search_products(const TRecipline& TProduct_);
	double calculate();
	bool dublicate_protect(const TRecipline& TProduct_);
public:

	void add_product(const TRecipline& TProduct_);
	void change_product(const TRecipline& TProduct_);
	void generate();

	const TReceipt& operator=(const TReceipt& receipt);
};

#endif