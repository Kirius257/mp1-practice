#pragma once
#ifndef TCONTAINER_H
#define TCONTAINER_H
#include "TRecipline.h"

//typedef TRecipline TElement;


//help: 
//Enumeration in C++ is a data type that allows you to define a new type consisting of a set of named constants.
//Constants in an enum can be assigned integer values, which can be used in a program to indicate certain states, flags or errors.


enum TContainerExeption { cntINDOUTOFRANGE, cntVALOUTOFRANGE };
template <class TELEM>
class TContainer {
protected:;
	int size;//size array
	int count_elements;//number of items
	TELEM* elements;//element array
	const static int sizestep = 1;
	void realloc(int dsize = 0);//increase the length of the container
public:
	TContainer(void);
	TContainer(int _size);
	TContainer(const TContainer& obj);
	~TContainer();
	TELEM& operator[](int index);//indexing by number
	TELEM& operator[](const TELEM& obj);//indexing by content
	TContainer& operator=(const TContainer& obj);

	void next();//move on element
	void back();//move up element
	void push_before();//insert element before
	void push_after();//insert element after

	int& get_count() { return count; }
	int& get_sizestep() { return sizestep; }

};

#endif