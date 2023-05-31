#pragma once
#ifndef TPRODUCT_H
#define TPRODUCT_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class TProduct {
	friend ostream& operator<<(ostream& stream, const TProduct& product);
private:
	long code;
	std::string name;
	double cost;
public:
	TProduct(void);
	TProduct(long code_, std::string name_, double cost_);
	TProduct(const TProduct& obj);

	void product_set(long code_, std::string name_, double cost_);

	void set_code(long code_) { code = code_; }
	long get_code()const { return code; }
	double get_cost() { return cost; }

	bool operator==(const TProduct& obj);
	TProduct& operator=(const TProduct& obj);
};
#endif