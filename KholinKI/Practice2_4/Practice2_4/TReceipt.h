#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H


#include "TContainer.h"
#include "TRecipline.h"





class TReceipt {
public:
	long index;							
	TDate* date;
	TTime* time;
	TContainer<TRecipline>* products;


	TReceipt();//create data and time for check:set default


	void changer();//redactor of check
	void find_product();//search
	void calculate_cost();//total cost purchase
};


class TDate {
public:
	int year;
	int month;
	int day;
};

class TTime {
public:
	int hour;
	int minute;
	int second;
};
#endif