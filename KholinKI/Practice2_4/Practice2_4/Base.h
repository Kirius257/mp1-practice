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
	pair<TProduct, int> convert(const TRecipline& obj);
public:
	Base(const std::string& path = "C://product_base.txt");
	int scanner(long code_)const;//get index product in base products
	bool operator<(const TRecipline& obj);


	int get_count()const { return count; }
	TProduct& get_product(int index);
	int& get_num(int index)const;
	
	void control(const TRecipline& obj);
	bool zero_check(const TRecipline& obj);
	//вывод чеков перегрузка <<
};
#endif