#include "TReceipt.h"
#include <fstream>
#include <iomanip>


TReceipt::TReceipt(void) {
	index = 0;

}

void TReceipt::file_reader(const std::string& path) {
	try
	{
		ifstream file(path);
		if (file.is_open() == 0) {
			throw Exeption<string>(NullPtrFile,path);
		}

		int k;
		file >> k;


		pair<TProduct, int> p;
		for (int i = 0; i < k; i++) {

			long code_;
			string name_;
			double cost_;
			int num_;
			file >> code_ >> name_ >> cost_ >> num_;
			TProduct tmp(code_, name_, cost_);
			p = make_pair(tmp, num_);
			my_base.push(p);
		}
	}
	catch (const Exeption<string>& ex) {
		ex.what();
	}
}
bool TReceipt::scanner(const TRecipline& TProduct_) {
	int res = my_base.find_b(TProduct_);
	if (res == -1) {
		return false;
	}
	else { return true; }
}

bool TReceipt::search_products(const TRecipline& TProduct_) {
	int res = products.find_t(TProduct_);
	if (res == -1) {
		return false;
	}
	else return true;
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
	TRecipline tmp = TProduct_;
	if (scanner(tmp)) {
		cout << "Product found!" << endl;
		int index = my_base.find_b(tmp);
		tmp.product = my_base[index].first;
		tmp.num = TProduct_.num;
		tmp.sum = tmp.product.get_cost() * tmp.num;
		//контроль количества товаров базы
		if (!dublicate_protect(tmp)) {
			int count = products.get_count();
			products.SELECT_PUSH(tmp);
		}
		else;;
	}
	else { throw Exeption<long>(NotFoundElement,tmp.product.get_code()); }
}

void TReceipt::change_product(const TRecipline& TProduct_) {
	TRecipline tmp = TProduct_;
	if (search_products(tmp)) {
		cout << "Product found!" << endl;
		int index = products.find_t(tmp);
		tmp = products[index];
		tmp.num = TProduct_.num;
		tmp.sum = tmp.num * tmp.product.get_cost();//#control cost
		products.replace(tmp, index);
	}
	else { throw Exeption<long>(NotFoundElement,tmp.product.get_code()); }
}

void TReceipt::generate() {
	CLOCK();
	cout << "				CHECK LIST" << endl;
	cout << left 
		 << setw(20)         << "CODE"
		 << setw(20)         << "NAME"
		 << setw(20)         << "COST"
		 << setw(20)         << "QUANTITY"
		 << setw(20)         << "SUMM";
	cout << endl;
	cout << products;
	cout << endl;
	double tc = calculate();
	cout << cout.precision(5) << "The total amount: " << tc << endl; 
	add_check(products);
}

void TReceipt::CLOCK() {
	cout << "CHECK #" << index << endl;
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

void TReceipt::add_check(const TContainer<TRecipline>& check) {
	checks.push(check);
	index++;
}
