#include <iostream>
#include <fstream>
#include "TReceipt.h"





using namespace std;


int main() {
	const string path = "C://product_base.txt";
	TReceipt check;//#CART OF BUYER

	file_reader(path, check);
	//int mode = 1;
	//int status = 1;
	//long product_code;
	//cout << "Welcome to the cash register!" << endl;
	//
	//do {
	//	int choice = -1;
	//	cout << "Choose an action:" << endl;
	//	cout << "1. Add a product to the receipt" << "\n"
	//		<< "2. Edit check line" << "\n"
	//		<< "3. Remove check line" << "\n"
	//		<< "4. Calculation of the total cost" << "\n";
	//	//SHOW CHECK
	//		cin >> choice;
	//		switch(choice) 
	//		{
	//		case 1: 
	//		{
	//			do {
	//				cout << "Input four-digits code: " << endl;
	//				cin >> product_code;
	//				TRecipline tmp = check.search_product_B(product_code);
	//				int _num = 0;
	//				if (tmp.product->cost < 0 || tmp.product->code == -1 || tmp.product->name == "") {
	//					cout << "Product not found!Try again" << endl;
	//				}
	//				else {
	//					cout << "Product found!" << endl;
	//					cout << "How much product do you need?" << endl;
	//					cin >> _num;
	//					tmp.num = _num;
	//					check.add_product(tmp);
	//					cout << "Product added! Continue?(1/0)" << endl;
	//					cin >> status;
	//				}
	//			} while (status == 1);
	//			break;
	//		}
	//		case 2: 
	//		{
	//			cout << "Input four-digits code: " << endl;
	//			cin >> product_code;
	//			TRecipline tmp = check.search_product_C(product_code);
	//			if (tmp.product->cost < 0 || tmp.product->code == -1 || tmp.product->name == "") {
	//				cout << "Product not found!Try again" << endl;
	//			}
	//			cout << "Change the quantity of the item from " << tmp.num << " to: ";
	//			//#EDIT
	//			int new_num;
	//			cin >> new_num;
	//			tmp.num = new_num;
	//			//#COMMIT CHANGE
	//			check.change_Cline(tmp);
	//		} break;
	//		case 3: cout << "CASE 3" << endl; break;
	//		case 4: cout << "CASE 4" << endl; break;
	//		default: mode = 0;
	//		}
	//} while (mode == 1);

	return 0;
}
