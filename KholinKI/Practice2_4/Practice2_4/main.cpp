#include <iostream>
#include <fstream>
#include "TReceipt.h"





using namespace std;


int main() {
	
	TReceipt check;//#CART OF BUYER

	const string path = "C://product_base.txt";
	check.file_reader(path);


	int mode = 1;
	int status = 1;
	long product_code;
	int product_num;
	cout << "Welcome to the cash register!" << endl;
	
	do {
		int choice = -1;
		cout <<  "Choose an action:" << endl;
		cout << "1. Add a product to the receipt" << "\n"
			 << "2. Change check line" << "\n"
			 << "3. Show contents of the cheque "<< "\n"
			 << "4. Generate check " << "\n"
			 << "5. Calculate total cost" << "\n";
		
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			do {
				TRecipline buying;
				cout << "Input four-digits code: " << endl;
				cin >> product_code;
				buying.product.set_code(product_code);

				cout << "How much product do you need?" << endl;
				cin >> product_num;
				buying.num = product_num;
				
				
				check.add_product(buying);
				cout << "Continue?(1/0)" << endl;
				cin >> status;
			} while (status == 1);
			break;
		}
		case 2:
		{
			TRecipline buying;
			cout << "What product do you want change?" << endl;
			cout << "Input four-digits code: " << endl;
			cin >> product_code;
			buying.product.set_code(product_code);

			cout << "Input new quantity of product" << endl;
			cin >> product_num;
			buying.num = product_num;

			check.change_product(buying);
			cout << "Check line changed!" << endl;
			break;
		} 
		case 3: cout << check << endl; break;
		case 4: cout << "CASE 4" << endl; break;
		case 5: cout << "CASE 5" << endl; break;
		default: mode = 0;
		}
	} while (mode == 1);

	return 0;
}
