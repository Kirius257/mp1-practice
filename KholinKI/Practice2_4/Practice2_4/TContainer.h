#pragma once
#ifndef TCONTAINER_H
#define TCONTAINER_H
#include "TRecipline.h"

typedef TRecipline TElement;

template <class TELEM>
class TContainer {
protected:
	TELEM* mass_elems;//element array
	int size;//size array
	int count_elements;//number of items
	TElement* elements;//triple bottom line
	const static int sizestep = 1;
	void resize(int dsize = 0);//increase the length of the container
public:
	TContainer(int _size);//
	TContainer(const TContainer& _cnt);
	~TContainer();
	TELEM& operator[](int index);//indexing by number
	TELEM& operator[](const TELEM& _ELM);//indexing by content
	
	void next();
	void back();
	void push_before();
	void push_after();

	int& Count() { return count; }
	int& Sizestep() { return sizestep; }
};

#endif