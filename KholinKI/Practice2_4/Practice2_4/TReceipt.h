#pragma once
#ifndef TRECEIPT_H
#define TRECEIPT_H

#include "TContainer.h"

class TReceipt {
public:
	long index;
	TDate* date;
	TTime* time;
	TContainer<?>* product;//КАКОЙ ТИП ЗДЕСЬ?

	//что значит удалить запись и добавить?
	void changer();//redactor of check
	void find_product();//search
	void calculate_cost();

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