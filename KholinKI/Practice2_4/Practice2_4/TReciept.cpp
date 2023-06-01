#include "TReceipt.h"
#include <fstream>
#include <iomanip>




//const objects using const methods

int TReceipt::search_products(const TRecipline& TProduct_)const {
	int ind = products.find_t(TProduct_);
	return ind;
}

bool TReceipt::operator==(const TRecipline& obj) {
	int ind = products.find_t(obj);
	if (ind != -1) {
		TRecipline& tmp = products[ind];
		tmp.num += obj.num;
		tmp.sum = tmp.num * tmp.product.get_cost();
		return true;
	}
	else return false;
}



void TReceipt::add_product(const TRecipline& TProduct_) {		
	products.push_back(TProduct_);
}

void TReceipt::change_product(const TRecipline& TProduct_) {
	int index = search_products(TProduct_);
	if (index != -1) {
		cout << "Product found!" << endl;
		TRecipline tmp;
		tmp = products[index];
		tmp.num = TProduct_.num;
		tmp.sum = tmp.num * tmp.product.get_cost();
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
	DataTime.SET_LOCAL_TIME();
	DataTime.OUTPUT_CLOCK();
}


double TReceipt::calculate()const {
	TRecipline item;
	double sum = 0.0;
	int count = products.get_count();
	for (int i = 0; i < count; i++) {
		item = products[i];
		sum += item.sum;
	}
	return sum;
}

ostream& operator<<(ostream& stream, const TReceipt& obj) {
	cout << "				CHECK LIST" << endl;
	cout << left
		<< setw(20) << "CODE"
		<< setw(20) << "NAME"
		<< setw(20) << "COST"
		<< setw(20) << "QUANTITY"
		<< setw(20) << "SUMM";
	cout << endl;
	stream << obj.products;
	return stream;
}

const TReceipt& TReceipt::operator=(const TReceipt& receipt) {
	DataTime = receipt.DataTime;
	products = receipt.products;
	return *this;
}