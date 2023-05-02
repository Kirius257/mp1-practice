#pragma once
#ifndef _TRECEIPT_H
#define _TRECEIPT_H


#include "TContainer.h"
#include "TRecipline.h"

class TReceipt {
private:
	long index;							
	TDate* date;
	TTime* time;
	TContainer* products;
public:
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