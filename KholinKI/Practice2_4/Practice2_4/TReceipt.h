#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H

#include "Container.h"
#include "TRecipline.h"
#include "Date.h"
#include "Time.h"



class TReceipt {
	friend void file_reader(const string& path, const TReceipt& check);
private:
	long index;
	TDate date;
	TTime time;
	TContainer<TRecipline> products;
	TContainer<pair<TProduct,int>> my_base;

public:
	TReceipt(void);

	void file_reader(const string& path);
};






#endif