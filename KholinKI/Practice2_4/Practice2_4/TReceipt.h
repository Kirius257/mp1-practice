#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H
#include "Container.h"
#include "TRecipline.h"
#include "Base.h"


class TReceipt {
	friend ostream& operator<<(ostream& stream, const TReceipt& obj);
private:
	TM DataTime;
	TContainer<TRecipline> products;	
	int search_products(const TRecipline& TProduct_)const;
	double calculate()const;
	void CLOCK();//не выводится дата-время
public:

	void add_product(const TRecipline& TProduct_);
	void change_product(const TRecipline& TProduct_);
	void generate();

	const TReceipt& operator=(const TReceipt& receipt);
	bool operator==(const TRecipline& obj);
};
#endif