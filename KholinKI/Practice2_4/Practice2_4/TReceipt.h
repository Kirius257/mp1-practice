#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H
#include "Container.h"
#include "TRecipline.h"


class TReceipt {
	
private:
	long index;
	TM DataTime;
	TContainer<TRecipline> products;
	TContainer<pair<TProduct,int>> my_base;
	TContainer<TContainer<TRecipline>> checks;
	bool scanner(const TRecipline& TProduct_);
	bool search_products(const TRecipline& TProduct_);
	bool dublicate_protect(const TRecipline& TProduct_);
	void add_check(const TContainer<TRecipline>& check);
	void CLOCK();
	double calculate();
public:
	TReceipt(void);

	void file_reader(const std::string& path);
	void add_product(const TRecipline& TProduct_);
	void change_product(const TRecipline& TProduct_);
	void generate();
};

#endif