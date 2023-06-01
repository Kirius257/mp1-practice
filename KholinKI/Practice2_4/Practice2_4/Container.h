#pragma once
#ifndef _CONTAINER_H
#define _CONTAINER_H

#include "Exeption.h"
#include "TRecipline.h"
#include <string>
#include <iostream>
#include <fstream>
#include "TM.h"



//help: 
//Enumeration in C++ is a data type that allows you to define a new type consisting of a set of named constants.
//Constants in an enum can be assigned integer values, which can be used in a program to indicate certain states, flags or errors.



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
	TContainer(int max_size = 100, int step = 100);
	TContainer(const TContainer<T>& obj);
	~TContainer();

	//#ITERATOR TOOLS
	bool is_ended() const;
	void next();
	void back();
	void reset();

	//#OPERATORS CONTAINER
	T& operator[](int index) const;
	const TContainer& operator=(const TContainer<T>& obj);
//	bool operator>(const T& obj);
	
	
	//#PUSHERS
//	void push_before(const T& obj);
	void push_back(const T& obj);
//	void push_after(const T& obj);
	
	//#INSERTS
	void insert(const T& obj,int index);

	//#REMOVING
	void remove(int index);
	
	//#METHODS OF WORKING WITH ELEMENT FIELDS
	int find_t(const T& elem)const;
	int find_pair(const pair<TProduct,int>& elem)const;
	
	
	//#REPLACEMENT
	void replace(const T& TProduct_, int index_);
	
	
	//#GETTERS
	int get_count()const { return count; }

	//#OUTPUT
	friend ostream& operator<<(ostream& stream, const TContainer<T>& container) {

		for (int i = 0; i < container.count; i++) {
			stream << container.element[i];
			stream << endl;
		}
		return stream;
	}

	//#SUPPORT
	void SELECT_PUSH(const T& obj);

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
	pos0 = obj.pos0;
	max_size = obj.max_size;
	count = obj.count;
	element = new T[max_size];
	step = obj.step;
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
	if (count == 0)return true;
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
void TContainer<T>::back() {
	pos0--;
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

//template <class T>
//void TContainer<T>::push_before(const T& obj) {
//	if (max_size == count) {
//		realloc();
//	}
//	while (is_ended() == false) {
//		next();
//	}
//	int i = 0;
//	for ( i = pos0+1; i > pos0-1; i--) {
//		element[i] = element[i - 1];
//	}
//	element[i] = obj;
//	count++;
//}

template <class T>
void TContainer<T>::push_back(const T& obj) {
	if (max_size == count) {
		realloc();
	}
	while (is_ended() == false) {
		next();
	}
	element[pos0] = obj;
	count++;
}

//template <class T>
//void TContainer<T>::push_after(const T& obj) {
//	if (max_size == count) {
//		realloc();
//	}
//	while (is_ended() == false) {
//		next();
//	}
//		next();
//	
//	element[pos0] = obj;
//	count++;
//}

template <class T>
void TContainer<T>::insert(const T& obj, int index) {
	if (index < 0 || index > count) {
		throw Exeption<int>(IndexLimitError,index);
	}
	if (max_size == count) {
		realloc();
	}
	for (int i = count-1; i >= index; i--) {
		element[i + 1] = element[i];
	}
	element[index] = obj;
	count++;
}




template <class T>
void TContainer<T>::remove(int index)
{
	if (index > -1 && index < count) {
		for (int i = index; i < count; i++) {
			element[i] = element[i + 1];
		}	
	}
	else { throw Exeption<int>(IndexLimitError, index); }
	count--;
}


template <class T>
T& TContainer<T>::operator[](int index)const {
	if (index < 0 || index >= count) {
		throw Exeption<int>(IndexLimitError, index);
	}
	return element[index];
}

//
//template <class T>
//bool TContainer<T>::operator>(const T& obj) {
//	int index = find_t(obj);
//	if (obj > element[index]) {
//		return true;
//	}
//	else return false;
//}


template <class T>
const TContainer<T>& TContainer<T>::operator=(const TContainer<T>& obj)
{
	count = obj.count;
	for (int i = 0; i < obj.count; i++) {
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
int TContainer<T>::find_pair(const pair<TProduct,int>& elem)const {
	int nom = -1;
	int i = 0;
	while (i < count && nom == -1) {
		if (element[i].first == elem.first) nom = i; else i++;
	}
	return nom;
}



template <class T>
void TContainer<T>::replace(const T& TProduct_, int index_) {
	remove(index_);
	insert(TProduct_, index_);
}

template <class T>
void TContainer<T>::SELECT_PUSH(const T& obj) {
	int choice=-1;
	if (count == 0) {
		push(obj);
	}
	else if (count == 1) {
		cout << "which method of addition do you want to use?" << endl;
		cout << "1. PUSH" << endl
			 << "2. PUSH AFTER" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {push(obj); break; }
		case 2: {push_after(obj); break; }
		default: throw Exeption<int>(ValidPush, choice);
		}
	}
	else if (count >= 2) {
		cout << "which method of addition do you want to use?" << endl;
		cout << "1. PUSH" << endl
			 << "2. PUSH AFTER" << endl
			 << "3. PUSH BEFORE" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {push(obj); break; }
		case 2: {push_after(obj); break; }
		case 3: {push_before(obj); break; }
		default: throw Exeption<int>(ValidPush, choice);
		}
	}
}
#endif