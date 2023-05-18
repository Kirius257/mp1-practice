#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H

#include "Pair.h"
#include "TRecipline.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


//help: 
//Enumeration in C++ is a data type that allows you to define a new type consisting of a set of named constants.
//Constants in an enum can be assigned integer values, which can be used in a program to indicate certain states, flags or errors.


enum class Exeption { NullPtrFile = -1, IndexLimitError = -2 };
template <class T>
class TContainer {
	//#SYSTEM FIELDS
private:
	int pos;
	int count;
	T* element;
	int max_size;
	int step;
	void realloc();
public:
	//#CONSTRUCTORS && DESTRUCTORS
///	TContainer(void);
	TContainer(int max_size = 10, int step = 5);
////	TContainer(int max_size, int step, const std::string& path);
	TContainer(const TContainer<T>& obj);
	~TContainer();

	//#ITERATOR TOOLS
	bool is_ended() const;
///	void end();
	void next();
	void reset();
///	int check_pos();

	//#OPERATORS CONTAINER
	T& operator[](int index);
	const TContainer& operator=(const TContainer<T>& obj);
	void push(const T& obj);
	void insert(int index);
	void insert_before(const T& obj);
	void insert_after(const T& obj);
	void remove(int index);
	
	//#METHODS OF WORKING WITH ELEMENT FIELDS
///	T find(long code_value) const;
	int  find(const T& elem) const;
	
};





template <class T>
TContainer<T>::TContainer(void) {
	pos = 0;
	count = 0;
	element = nullptr;
	max_size = 0;
	step = 0;
}

template <class T>
TContainer<T>::TContainer(int max_size,int step) {
	pos = 0;
	count = 0;
	this->max_size = 100;
	this->step = 10;

	element = new T[this->max_size];
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
void TContainer<T>::end() {

	while (check_pos() == 0) {
		next();
	}

}

template <class T>
int TContainer<T>::check_pos() {
	int def1 = 0;
	if (element[pos].product == nullptr && element[pos + 1].product != nullptr) { def1 = 1; return def1; }
	int def2 = 0;
	if (element[pos].product == nullptr && element[pos - 1].product != nullptr && (pos - 1) > 0) { def2 = 1; return def2; }
	if (def1 == 1 && def2 == 1) {
		int def3 = true;
		return def3;
	}
	return 0;
}

template <class T>
void TContainer<T>::next() {
	pos++;
}

template <class T>
void TContainer<T>::reset() {
	pos = 0;
}

template <class T>
void TContainer<T>::realloc() {
	max_size += step;
	T* tmp_element = new T[max_size];
	for (int i = 0; i < count; i++) { tmp_element[i] = element[i]; }
	element = tmp_element;
}



template <class T>
void TContainer<T>::insert_end(const T& obj) {
	if (max_size == count) {
		realloc();
		reset();
	}
	end();
	element[pos].num = obj.num;
	element[pos].product = new TProduct(*(obj.product));
	count++;
	reset();
}

template <class T>//method find by code value
T TContainer<T>::find(long code_value) const{
	for (pos = 0; pos < count; next())
	{
		if (element[pos].product->code == code_value) { 
			return element[pos];
		}
	}
	return T();
}

template <class T>
void TContainer<T>::remove(int index)
{
	if (index > -1 && index < count)
		for (int i = index; i < count - 1; i++)
			element[i] = element[i + 1];
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
TContainer<T>& TContainer<T>::operator=(const TContainer<T>& obj) 
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
TContainer<T>::TContainer(int max_size,int step,const std::string& path) {
	try {
		ifstream file(path);
		if (file.is_open() == 0) {
			Exeption ex = Exeption::NullPtrFile;//get access ::
			throw ex;
		}

		pos = 0;
		count = 0;
		this->max_size = max_size;
		this->step = step;

		element = new T[max_size];

		int k;
		file >> k;

		int num_;
		long code_;
		std::string name_;
		double cost_;

		
		for (int i = 0; i < k; i++) {
			file >> num_ >> code_ >> name_ >> cost_;
			T tmp(num_, code_, name_, cost_);
			insert_end(tmp);
		}
		file.close();
		
	}
	catch (Exeption ex) {
		cout << "Check that the file path is correct! Programm is over with code " << static_cast<int>(ex) << endl;
	}
}

template <class T>
int TContainer<T>::find(const T& elem) const {
	int nom = -1;
	int i = 0;
	while (i < count && nom == -1) {
		if (element[i] == elem) nom = i; else i++;
	}
	return nom;
}

#endif