#pragma once
#ifndef TPRODUCT_H
#define TPRODUCT_H

#include <string>



class TProduct {
private:
	long code;
	std::string name;
	double cost;
public:
	TProduct(void);
	TProduct(long code_, std::string name_, double cost_);
	TProduct(const TProduct& obj);

	void set_code(long code_) { code = code_; }
	bool operator==(const TProduct& obj);
};
#endif