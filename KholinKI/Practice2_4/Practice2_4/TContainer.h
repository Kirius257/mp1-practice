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

enum class FileExeption { NullPtrFile = -1 };
class TContainer {
private:
	int size;
	elements* element;
	int max_size;
	int step;
public:
	TContainer(int max_size, int step);
	void file_reader(ifstream& file);
};

#endif