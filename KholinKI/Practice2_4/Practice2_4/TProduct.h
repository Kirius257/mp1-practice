#pragma once
#ifndef TPRODUCT_H
#define TPRODUCT_H

#include <string>



struct TProduct {//class

	// private fields
	long code;
	std::string name;
	double cost;

	TProduct(void);
	TProduct(long code_, std::string name_, double cost_);
	TProduct(const TProduct& obj);
};
#endif