#include "TReceipt.h"

TReceipt::TReceipt(int max_size,int step,const string& path) {
	//#Creating containers
	index = 0;
	products = new TContainer<TRecipline>(max_size,step);
	my_base = new TContainer<Pair>(max_size, step,path);
	
}


TRecipline TReceipt::search_product_B(long code_) {
	Pair element = my_base->find(code_);
	if (element.product == nullptr){ return TRecipline(-1,-1, "", -1); }
	return TRecipline(0, element.product->code, element.product->name, element.product->cost);
}

TRecipline TReceipt::search_product_C(long code_) {
	TRecipline element = products->find(code_);
	if (element.product == nullptr) { return TRecipline(-1, -1, "", -1); }
	return element;
}

void TReceipt::add_product(const TRecipline& obj) {
	products->insert_end(obj);
}

void TReceipt::change_Cline(const TRecipline& obj) {

	//products->insert_end(obj); //!Не подходит. Нужна вставка перед или после
	//Найти номер и вставить перед или после 
}