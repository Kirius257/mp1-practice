#pragma once
#ifndef _TRECEIPT_H
#define _TRECEIPT_H

#include <chrono>
#include "Date.h"
#include "Time.h"
#include "TContainer.h"

enum class FileExeption { NullPtrFile = -1 };
class TReceipt {
private:
	int num_conts;
	long index;							
	TDate* date;
	TTime* time;
	TContainer** products;
public:
	TReceipt(int num_c,const string& path);

	
	//void add_product(const TProduct& obj);
};




#endif