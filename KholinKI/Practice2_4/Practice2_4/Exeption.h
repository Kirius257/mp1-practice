#pragma once
#ifndef _EXEPTION_H
#define _EXEPTION_H
#include <iostream>

using namespace std;

enum TypeExeption { NullPtrFile, IndexLimitError, NotFoundElement, NotFoundCheckMethod, NumProductLimit };
template <class T>
class Exeption {
private:
	TypeExeption type;
	T WrongValue;
public:
	Exeption(TypeExeption type_, T WrongValue_);

	void what()const;
};

template <class T>
Exeption<T>::Exeption(TypeExeption type_, T WrongValue_):type(type_),WrongValue(WrongValue_){}

template <class T>
void Exeption<T>::what()const {
	switch (type) 
	{
	case NullPtrFile: {cout << "File  with path " << WrongValue << " not found!Check that the path is correct" << endl; abort();  break;  }
	case IndexLimitError: { cout << "Index " << WrongValue <<  " is outside the range of the filled part of the container" << endl;  break; }
	case NotFoundElement: { cout << "Element with code " << WrongValue << " not exists!" << endl;  break; }
	case NotFoundCheckMethod: { cout << "The switch operator did not find a cheque method with this number " << WrongValue << endl;  break; }
	case NumProductLimit: { cout << "You cannot take more than what is in stock!Take less than " << WrongValue << endl;  break; }
	}
}
#endif