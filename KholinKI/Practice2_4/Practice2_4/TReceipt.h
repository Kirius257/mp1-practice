#pragma once
#ifndef _TRECEIPT_H
#define _TRECEIPT_H

#include "Date.h"
#include "Time.h"
#include "TContainer.h"


class TReceipt {
private:
	long index;							
	TDate* date;
	TTime* time;
	TContainer* products;
public:
};




#endif