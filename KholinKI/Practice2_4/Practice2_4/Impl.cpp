#include "TReceipt.h"


#include <fstream>
#include <iostream>
//#1 BASE OF PRODUCTS
//#2 CONTAINER

using namespace std;

void TContainer::next(long& index) {
	index++;
}

void TContainer::back(long& index) {
	index--;
}


void TContainer::insert_end(const TProduct& obj,long& index) {
	//проверка на переполнение;realloc() здесь
	if (element[index]->check_end() || index == max_size - 1) {
		back(index);

	}
	//на i-той вставке проконтролировать заполнение
	else next(index);
}

bool TRecipline::check_end() {//додумать,как правильно найти конец
	if (product != nullptr) {
		return true;
	}
	else return false;
}

void TContainer::get_data_base(const string& path,long& index) {
	try {
		ifstream file(path);
		if (file.is_open() == 0) {
			FileExeption ex = FileExeption::NullPtrFile;//get access ::
			throw ex;
		}

		file >> count;
		//проверка на переполнение
		int num_;
		long code_;
		string name_;
		double cost_;
		
		for (int i = 0; i < count; i++) {
			file >> num_ >> code_ >> name_ >> cost_;
			element[i] = new elements(num_);
			TProduct tmp(code_,name_,cost_);
			insert_end(tmp,index);
		}
		
		file.close();
	}
	catch (FileExeption ex) {
		cout << "Check that the file path is correct! Programm is over with code " << static_cast<int>(ex) << endl;
	}
}

//void TContainer::insert_end() {
//	int pos = max_size-1;
//	if(element[pos] )
//}
//отталкиваться от pos и через цикл найти свободное место.




//int product_base::scanner1_0(long& code) {
//	for (int i = 0; i < count; i++) {
//		if (d_base[i].get_code() == code) {
//			return 1;
//		}
//	}
//	return 0;
//}

//void TContainer::realloc() {

//}

//void TContainer::insert() {
//	//if (size > max_size) realloc();
//	
//	increase_size();
//}
