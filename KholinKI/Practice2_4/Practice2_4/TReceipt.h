#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H
#include "Container.h"
#include "TRecipline.h"
#include "Date.h"
#include "Time.h"



class TReceipt {
	friend ostream& operator<<(ostream& stream, const TReceipt& check);
private:
	long index;
	TDate date;
	TTime time;
	TContainer<TRecipline> products;
	TContainer<pair<TProduct,int>> my_base;
	bool scanner(const TRecipline& TProduct_);
	bool search_products(const TRecipline& TProduct_);
	bool dublicate_protect(const TRecipline& TProduct_);
public:
	TReceipt(void);

	void file_reader(const std::string& path);
	void add_product(const TRecipline& TProduct_);
	void change_product(const TRecipline& TProduct_);
	void calculate();
	
};

#endif