#pragma once
#ifndef _BASE_H
#define _BASE_H

#include "Container.h"
#include <iostream>
#include "Exeption.h"

class Base {
private:
	TContainer<pair<TProduct, int>> my_base;
	int count;
public:
	Base(const std::string& path = "C://product_base.txt");
	int scanner(long code_)const;//get index product in base products
	int get_count()const { return count; }
	TProduct& get_product(int index);

	//вывод чеков перегрузка <<
};




#endif