#include <iostream>
#include <string>
#include "TContainer.h"


using namespace std;

TContainer::TContainer(int max_size, int step) {
	try {
		ifstream file;
		const string path = "C://product_base.txt";
		file.open(path);
		if (file.is_open() == 0) {
			FileExeption ex = FileExeption::NullPtrFile;//get access ::
			throw ex;
		}

		this->max_size = max_size;
		this->step = step;

		element = new elements[this->max_size];


	}
	catch (FileExeption ex) {
		cout << "Check that the file path is correct! Programm is over with code " << static_cast<int>(ex) << endl;
	}
	
}