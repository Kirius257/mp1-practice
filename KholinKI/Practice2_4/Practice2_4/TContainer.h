#pragma once
#ifndef _TCONTAINER_H
#define _TCONTAINER_H
#include "TRecipline.h"
#include <fstream>


using namespace std;


//help: 
//Enumeration in C++ is a data type that allows you to define a new type consisting of a set of named constants.
//Constants in an enum can be assigned integer values, which can be used in a program to indicate certain states, flags or errors.

typedef TRecipline elements;

class TContainer {
private:
	int pos;
	int count;
	elements* element;
	int max_size;
	int step;
	void realloc();
public:
	TContainer(int max_size, int step);

	void get_data_base(const string& path);
	//TContainer(int count); ��� ����������-���������
	//

	void next();
	void reset();
	void end();
	void insert_end(const TProduct& obj);
	
	//����������� ����������� ��� ����������� ����
	//���������� ��� ������������ ������ ��-��� element

};

#endif