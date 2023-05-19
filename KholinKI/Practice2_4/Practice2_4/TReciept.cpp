#include "TReceipt.h"


TReceipt::TReceipt(void){
	index = 0;
	
}

void TReceipt::file_reader(const string& path) {
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
			int num_;
			long code_;
			string name_;
			double cost_;
			file >> num_ >> code_ >> name_ >> cost_;
			TProduct tmp(code_, name_, cost_);
			p = make_pair(tmp, num_);
			my_base.push(p);
		}

	}
	catch (Exeption ex) {
		cout << "Called exeption: " << static_cast<int>(ex) << endl;
	}
}


//void TReceipt::change_Cline(const TRecipline& obj) {
//
//	//products->insert_end(obj); //!Не подходит. Нужна вставка перед или после
//	//Найти номер и вставить перед или после 
//}