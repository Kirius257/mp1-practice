#include "TReceipt.h"
#include <fstream>
#include <iomanip>






int TReceipt::search_products(const TRecipline& TProduct_) {
	int ind = products.find_t(TProduct_);
	return ind;
}

bool TReceipt::dublicate_protect(const TRecipline& obj) {
	int ind = products.find_t(obj);
	if (ind != -1) {
		cout << "The product in question already exists!" << "\n"
			<< "If you would like to change the quantity," << "\n"
			<< "go to the Change check line" << "\n";
		return true;
	}
	else return false;
}



void TReceipt::add_product(const TRecipline& TProduct_) {		
		//контроль количества товаров базы
		if (!dublicate_protect(TProduct_)) {
			products.push_back(TProduct_);
		}
		else;;
}

void TReceipt::change_product(const TRecipline& TProduct_) {
	int index = search_products(TProduct_);
	if (index != -1) {
		cout << "Product found!" << endl;
		TRecipline tmp;
		tmp = products[index];
		tmp.num = TProduct_.num;
		tmp.sum = tmp.num * tmp.product.get_cost();//#control cost
		products.replace(tmp, index);
	}
	else { throw Exeption<long>(NotFoundElement, TProduct_.product.get_code()); }
}

void TReceipt::generate() {
	CLOCK();
	cout << "				CHECK LIST" << endl;
	cout << left
		<< setw(20) << "CODE"
		<< setw(20) << "NAME"
		<< setw(20) << "COST"
		<< setw(20) << "QUANTITY"
		<< setw(20) << "SUMM";
	cout << endl;
	cout << products;
	cout << endl;
	double tc = calculate();
	cout << cout.precision(5) << "The total amount: " << tc << endl;
}

void TReceipt::CLOCK() {
	DataTime.SYSTEM_C();
	DataTime.OUTPUT_SYSTEM_C();
}


double TReceipt::calculate() {
	TRecipline item;
	double sum = 0.0;
	int count = products.get_count();
	for (int i = 0; i < count; i++) {
		item = products[i];
		sum += item.sum;
	}
	return sum;
}

const TReceipt& TReceipt::operator=(const TReceipt& receipt) {
	DataTime.SYSTEM_C();
	products = receipt.products;
	return *this;
}
