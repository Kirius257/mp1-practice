#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H

#include "Container.h"
#include "TRecipline.h"
#include "Date.h"
#include "Time.h"

#define MAX_SIZE 3
#define STEP 10


class TReceipt {
private:
	long index;
	TDate* date;
	TTime* time;
	TContainer<TRecipline>* products;
	TContainer<Pair>* my_base;
public:
	TReceipt(int max_size,int step,const string& path);
	
	//#SCANNERS
	TRecipline search_product_B(long code_);
	TRecipline search_product_C(long code_);

	//#ADD
	void add_product(const TRecipline& obj);

	//#CHANGE
	void change_Cline(const TRecipline& obj);
};





#endif