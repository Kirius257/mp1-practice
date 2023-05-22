#pragma once
#ifndef _CONTAINER_H
#define _CONTAINER_H


#include "TRecipline.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


//help: 
//Enumeration in C++ is a data type that allows you to define a new type consisting of a set of named constants.
//Constants in an enum can be assigned integer values, which can be used in a program to indicate certain states, flags or errors.


enum class Exeption { NullPtrFile, IndexLimitError, NotFoundElement };
template <class T>
class TContainer {
	
	//#SYSTEM FIELDS
private:
	int pos0;
	int count;
	T* element;
	int max_size;
	int step;
	void realloc();
public:
	//#CONSTRUCTORS && DESTRUCTOR
	TContainer(int max_size = 1, int step = 5);
	TContainer(const TContainer<T>& obj);
	~TContainer();

	//#ITERATOR TOOLS
	bool is_ended() const;
	void next();
	void reset();

	//#OPERATORS CONTAINER
	T& operator[](int index);
	const TContainer& operator=(const TContainer<T>& obj);
	
	
	void push(const T& obj);
	void insert(const T& obj,int index);
	//void insert_before(const T& obj);
	//void insert_after(const T& obj);
	void remove(int index);
	
	//#METHODS OF WORKING WITH ELEMENT FIELDS
	int find_t(const T& elem) const;//find between their
	int find_b(const TRecipline& TProduct);//get index product in base products
	

	//#GETTERS
	int get_count() { return count; }

	//#OUTPUT
	friend ostream& operator<<(ostream& stream, const TContainer<T>& container) {
		for (int i = 0; i < container.count; i++) {
			stream << container.element[i];
			stream << endl;
		}
		return stream;
	}
};



template <class T>
TContainer<T>::TContainer(int max_size,int step) {
	pos0 = 0;
	count = 0;
	this->max_size = max_size;
	this->step = step;

	element = new T[max_size];
}


template <class T>
TContainer<T>::TContainer(const TContainer<T>& obj) {
	max_size = obj.max_size;
	count = obj.count;
	element = new T[max_size];
	for (int i = 0; i < count; i++){
		element[i] = obj.element[i];
	}
}


template <class T>
TContainer<T>::~TContainer() {
	if (count > 0) {
		if (element != nullptr) {
			delete[] element;
		}
		max_size = 0;
		count = 0;
		element = nullptr;
	}
}

template <class T>
bool TContainer<T>::is_ended()const {
	if (pos0 == count) {
		return true;
	}
	else return false;
}



template <class T>
void TContainer<T>::next() {
	pos0++;
}

template <class T>
void TContainer<T>::reset() {
	pos0 = 0;
}

template <class T>
void TContainer<T>::realloc() {
	max_size += step;
	T* tmp_element = new T[max_size];
	for (int i = 0; i < count; i++) { tmp_element[i] = element[i]; }
	element = tmp_element;
}



template <class T>
void TContainer<T>::push(const T& obj) {
	if (max_size == count) {
		realloc();
	}
	while (is_ended() == false) {
		next();
	}

	element[pos0] = obj;
	count++;
}

template <class T>
void TContainer<T>::insert(const T& obj, int index) {
	if (index < 0 || index >= count) {
		Exeption ex = Exeption::IndexLimitError;
		throw ex;
	}
	if (max_size == count) {
		realloc();
	}
	for (int i = count-1; i >= index; i--) {
		element[i + 1] = element[i];
	}
	element[index] = obj;
}



template <class T>
void TContainer<T>::remove(int index)
{
	if (index > -1 && index < count) {
		for (int i = index; i < count; i++) {
			element[i] = element[i + 1];
		}	
	}
	else { Exeption ex = Exeption::IndexLimitError; throw ex; }
	count--;
}


template <class T>
T& TContainer<T>::operator[](int index) {
	if (index < 0 || index >= count) {
		Exeption ex = Exeption::IndexLimitError;
		throw ex;
	}
	return element[index];
}



template <class T>
const TContainer<T>& TContainer<T>::operator=(const TContainer<T>& obj)
{
	if (this != &obj) {
		delete[] element;
		size = obj.size;
		count = obj.count;
		element = new T[size];
		for (int i = 0; i < count; i++)
			element[i] = obj.element[i];
	}
	return *this;
}




template <class T>
int TContainer<T>::find_t(const T& elem) const {
	int nom = -1;
	int i = 0;
	while (i < count && nom == -1) {
		if (element[i].product == elem.product) nom = i; else i++;
	}
	return nom;
}

template <class T>
int TContainer<T>::find_b(const TRecipline& TProduct) {
	int nom = -1;
	int i = 0;
	while (i < count && nom == -1) {
		if (element[i].first == TProduct.product) {
			nom = i; 
		}
		else i++;
	}
	return nom;
}


#endif