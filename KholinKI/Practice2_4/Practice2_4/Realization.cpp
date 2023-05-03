#include "TReceipt.h"
#include "product_base.h"
#include "TContainer.h"

#include <fstream>


using namespace std;

void description_base::file_read(ifstream& file) {
	file >> code >> name >> cost;

}

int product_base::scanner1_0(long& code) {
	for (int i = 0; i < count; i++) {
		if (d_base[i].get_code() == code) {
			return 1;
		}
	}
	return 0;
}

void TContainer::realloc() {

}

void TContainer::insert() {
	//if (size > max_size) realloc();
	
	increase_size();
}
