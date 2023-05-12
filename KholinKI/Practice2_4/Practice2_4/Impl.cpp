#include "TReceipt.h"


#include <fstream>
#include <iostream>
//#1 BASE OF PRODUCTS
//#2 CONTAINER

using namespace std;

void TContainer::end() {
	int tmp_i = 0;
	tmp_i = max_size - count - 1;
	if (tmp_i < 0) {
		pos = -1;
	}
	while (pos < tmp_i)
	{
		next();
	}
	if (pos > tmp_i && (pos - tmp_i) == 1) {
		pos = tmp_i;
	}
}

void TContainer::next() {
	pos++;
}

void TContainer::reset() {
	pos = 0;
}

void TContainer::realloc() {
	max_size += step;
	elements* tmp_element = new elements[max_size];
	for (int i = 0; i < count; i++)
		tmp_element[i] = element[i];
	delete[] element;
	element = tmp_element;
}



void TContainer::insert_end(const TProduct& obj) {
	end();

	if (pos < 0) {
		realloc();
		reset();
		end();
	}
	element[pos].product = new TProduct(obj.code, obj.name, obj.cost);//конструктор копирования,может быть?
	count++;
}



void TContainer::get_data_base(const string& path) {
	try {
		ifstream file(path);
		if (file.is_open() == 0) {
			FileExeption ex = FileExeption::NullPtrFile;//get access ::
			throw ex;
		}

		int k;
		file >> k;
		int num_;
		long code_;
		string name_;
		double cost_;
		
		for (int i = 0; i < k; i++) {
			file >> num_ >> code_ >> name_ >> cost_;
			TProduct tmp(code_,name_,cost_);
			insert_end(tmp);
			element[pos].num = num_;//количество сделать 0,мы считаем его в структуру pair(из библиотеки)
			
		}
		file.close();
	}
	catch (FileExeption ex) {
		cout << "Check that the file path is correct! Programm is over with code " << static_cast<int>(ex) << endl;
	}
}

//int product_base::scanner1_0(long& code) {
//	for (int i = 0; i < count; i++) {
//		if (d_base[i].get_code() == code) {
//			return 1;
//		}
//	}
//	return 0;
//}




