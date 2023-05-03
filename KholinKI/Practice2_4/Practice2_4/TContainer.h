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
	int size;
	elements* element;
	int max_size;
	int step;
	void realloc();
public:
	TContainer(void);
	TContainer(int max_size, int step);
	//ÊÎÍÑÒĞÓÊÒÎĞ ÊÎÏÈĞÎÂÀÍÈß ÄËß ÏÅĞÅÏÀÊÎÂÊÈ ÑŞÄÀ
	//ÄÅÑÒĞÓÊÒÎĞ ÄËß ÎÑÂÎÁÎÆÄÅÍÈß ÏÀÌßÒÈ ÈÇ-ÏÎÄ element


	void insert();//ÏÀĞÀÌÅÒĞÛ?

	void increase_size() { size++; }
	int get_size() { return size; }
	int get_max_size() { return max_size; }
	
};

#endif