#pragma once
#ifndef _TRECEIPT_H
#define _TRECEIPT_H


#include "Date.h"
#include "Time.h"
#include "TContainer.h"



template <class T>
class TReceipt {
private:
	long index;							
	TDate* date;
	TTime* time;
	TContainer<T>* products;
public:
	TReceipt(void);
	//void add_product(const TProduct& obj);
};

template <class T>
TReceipt<T>::TReceipt(void) {
	//#Creating containers
	products = new TContainer<T>(3, 10);
}



#endif