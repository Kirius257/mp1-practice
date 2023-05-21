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
bool TReceipt::search_base(const TRecipline& TProduct_) {
	int res = my_base.find_bbbb(TProduct_);
	if (res == -1) {
		return false;
	}
	else { return true; }
}


void TReceipt::add_product(const TRecipline& TProduct_) {
	TRecipline tmp = TProduct_;
	if (search_base(TProduct_)) {
		int index = my_base.find_bbbb(TProduct_);
		tmp.product = my_base[index].first;
		tmp.num = TProduct_.num;
		products.push(TProduct_);
	}
	else { Exeption ex = Exeption::NotFoundElement; throw ex; }
}



//void TReceipt::change_Cline(const TRecipline& obj) {
//
//	//products->insert_end(obj); //!Не подходит. Нужна вставка перед или после
//	//Найти номер и вставить перед или после 
//}