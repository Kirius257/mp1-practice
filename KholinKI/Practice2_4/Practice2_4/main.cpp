#include <iostream>
#include <fstream>
#include "TReceipt.h"





using namespace std;


int main() {
	const string path = "C://product_base.txt";
	TReceipt<TRecipline>check();//#CART OF BUYER
	TContainer<Pair>my_base(path);//#BASE OF PRODUCT

	return 0;
}
