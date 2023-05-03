#include <iostream>
#include <string>
#include "TReceipt.h"
#include "TContainer.h"
#include "product_base.h"



using namespace std;

TContainer::TContainer(int max_size, int step) {
		this->max_size = max_size;
		this->step = step;
		

		element = new elements[this->max_size];
	
}

description_base::description_base(void) {
	code = 0;
	name = "";
	cost = 0;
}

TContainer::TContainer(void) {
	size = -1;
	element = nullptr;
	max_size = 0;
	step = 1;
}


product_base::product_base(const std::string& path) {
	try {
		ifstream file;
		file.open(path);
		if (file.is_open() == 0) {
			FileExeption ex = FileExeption::NullPtrFile;//get access ::
			throw ex;
		}
		file >> count;
		d_base = new description_base[count];
		for (int i = 0; i < count; i++) {
			d_base[i].file_read(file);
		}
		file.close();
	}
	catch (FileExeption ex) {
		cout << "Check that the file path is correct! Programm is over with code " << static_cast<int>(ex) << endl;
	}
	
}

product_base::~product_base() {
	delete[] d_base;
}