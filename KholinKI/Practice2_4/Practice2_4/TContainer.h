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
	int count;
	elements** element;
	int max_size;
	int step;
	//void realloc();
public:
	TContainer(int max_size, int step);

	void get_data_base(const string& path,long& index);
	//TContainer(int count); äëÿ êîíòåéíåğà-îğèãèíàëà
	//

	void next(long& index);
	void back(long& index);
	void insert_end(const TProduct& obj,long& index)
	
	//ÊÎÍÑÒĞÓÊÒÎĞ ÊÎÏÈĞÎÂÀÍÈß ÄËß ÏÅĞÅÏÀÊÎÂÊÈ ÑŞÄÀ
	//ÄÅÑÒĞÓÊÒÎĞ ÄËß ÎÑÂÎÁÎÆÄÅÍÈß ÏÀÌßÒÈ ÈÇ-ÏÎÄ element

};

#endif