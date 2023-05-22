#include "TReceipt.h"
#include <fstream>

TReceipt::TReceipt(void){
	index = 0;
	
}

void TReceipt::file_reader(const std::string& path) {
	try
	{
		ifstream file(path);
		if (file.is_open() == 0) {
			Exeption ex = Exeption::NullPtrFile;
			throw ex;
		}

		int k;
		file >> k;


		pair<TProduct, int> p;
		for (int i = 0; i < k; i++) {
			
			long code_;
			string name_;
			double cost_;
			int num_;
			file >>  code_ >> name_ >> cost_ >> num_;
			TProduct tmp(code_, name_, cost_);
			p = make_pair(tmp, num_);
			my_base.push(p);
		}
	}
	catch (Exeption ex) {
		cout << "Called exeption: " << static_cast<int>(ex) << endl;
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
		cout <<  "The product in question already exists!"  << "\n"
			 << "If you would like to change the quantity," << "\n"
		   	 <<       "go to the Change check line"			<< "\n";
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
		if (!dublicate_protect(tmp)) {
			products.push(tmp);
		}
		else ;;
	}
	else { Exeption ex = Exeption::NotFoundElement; throw ex; }
}

void TReceipt::change_product(const TRecipline& TProduct_) {
	TRecipline tmp = TProduct_;
	if (search_products(tmp)) {
		cout << "Product found!" << endl;
		int index = products.find_t(tmp);
		tmp = products[index];
		tmp.num = TProduct_.num;
		products.remove(index);
		products.insert(tmp, index);
	}
	else { Exeption ex = Exeption::NotFoundElement; throw ex; }
}

ostream& operator<<(ostream& stream, const TReceipt& check) {
	stream << "			CHECK LIST" << endl;
	stream << "CODE		NAME		COST		QUANTITY		SUMM" << endl;
	stream << check.products;
	stream << endl;
	return stream;
}

void TReceipt::calculate() {
	double sum =
}

