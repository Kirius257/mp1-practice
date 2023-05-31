#include <iostream>
#include <fstream>
#include "TReceipt.h"
#include "Base.h"
#include "Shop.h"






int main() {
	Shop checks;
	Base data;


	int cash_register_mode = 1;
	int mode = 1;
	int status = 1;
	long product_code;
	int product_num;
	int choice = - 1;
	try {
	do {
		TReceipt check;//#CART OF BUYER
			cout << "Welcome to the cash register!" << endl;
			do {
				cout << "Choose an action:" << endl;
				cout << "1. Add a product to the receipt" << "\n"
					 << "2. Change check line" << "\n"
					 << "3. Generate check " << "\n";
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

						int index = data.scanner(product_code);
						if (index != -1) {
							cout << "Product found!" << endl;
							buying.product = data.get_product(index);
							buying.sum = buying.product.get_cost() * buying.num;
						}
						else { throw Exeption<long>(NotFoundElement, product_code); }

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
				case 3:
				{
					cout << "CHECK #" << checks.get_num() << endl;
					check.generate();
					checks.add(check);
					cout << endl << endl << endl
						 << "Thanks for purchase!Come to our shop again!^^" 
						 << endl;
					mode = 0;
					break;
				}
				default: throw Exeption<int>(NotFoundCheckMethod, choice);
				}
			} while (mode == 1);

			cout << "SYSTEM MESSAGE: serve the next customer?(1/0)" << endl;
			cin >> cash_register_mode;
			if (cash_register_mode != 0 && cash_register_mode != 1) {
				throw Exeption<int>(ValidMode, cash_register_mode);
			}
		} while (cash_register_mode == 1);
		checks.show();
	}
	catch(const Exeption<int> ex){
		ex.what();
	}
	catch (const Exeption<long> ex) {
		ex.what();
	}
	
	return 0;
}
