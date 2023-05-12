#pragma once
#ifndef _TPRODUCT_H
#define _TPRODUCT_H

#include <string>



struct TProduct {
	long code;
	std::string name;
	double cost;

	TProduct(void);
	TProduct(long code_, std::string name_, double cost_);
	TProduct(const TProduct& obj);
};
#endif