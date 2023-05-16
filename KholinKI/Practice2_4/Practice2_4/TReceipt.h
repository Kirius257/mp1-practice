#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H

#include "Container.h"
#include "TRecipline.h"
#include "Date.h"
#include "Time.h"




class TReceipt {
private:
	int num_conts;
	long index;
	TDate* date;
	TTime* time;
	TContainer<TRecipline>* products;
public:
	TReceipt(int num_conts);
	
};


TReceipt::TReceipt(int num_conts_) {
	//#Creating containers
	index = 0;
	int num_conts = num_conts_;
	products = new TContainer<TRecipline>(3, 10);
}

#endif