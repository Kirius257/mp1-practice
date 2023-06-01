#include "Base.h"




Base::Base(const std::string& path) {
	try
	{
		ifstream file(path);
		if (file.is_open() == 0) {
			throw Exeption<string>(NullPtrFile, path);
		}

		file >> count;

		TProduct tmp;


		pair<TProduct, int> p;
		for (int i = 0; i < count; i++) {

			long code_;
			string name_;
			double cost_;
			int num_;
			file >> code_ >> name_ >> cost_ >> num_;
			tmp.product_set(code_, name_, cost_);
			p = make_pair(tmp, num_);
			my_base.push_back(p);
		}
	}
	catch (const Exeption<string>& ex) {
		ex.what();
	}
}


int Base::scanner(long code_) const {
	int nom = -1;
	pair<TProduct, int> p_tmp;
	for (int i = 0; i < count; i++) {
		p_tmp = my_base[i];
		if (p_tmp.first.get_code() == code_) {
			nom = i;
			return nom;
		}
	}
	return nom;
}


TProduct& Base::get_product(int index) {
	if (index < 0 || index > my_base.get_count())
	{
		throw Exeption<int>(IndexLimitError, index);
	}
	return my_base[index].first;
}

int& Base::get_num(int index)const {
	if (index < 0 || index > my_base.get_count())
	{
		throw Exeption<int>(IndexLimitError, index);
	}
	return my_base[index].second;
}

bool Base::zero_check(const TRecipline& obj) {
	int index = my_base.find_pair(convert(obj));
	int num = my_base[index].second;
	if (num == 0) {
		return true;
	}
	else return false;
}

bool Base::operator<(const TRecipline& obj) {
	int index = my_base.find_pair(convert(obj));
	if (my_base[index].second < obj.num ) {
		return true;
	}
	else return false;
}

pair<TProduct,int> Base::convert(const TRecipline& obj) {
	pair<TProduct, int> p = make_pair(obj.product, obj.num);
	return p;
}

void Base::control(const TRecipline& obj) {
	int index = my_base.find_pair(convert(obj));
	my_base[index].second -=  obj.num;
}