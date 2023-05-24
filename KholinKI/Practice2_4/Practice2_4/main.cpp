#include <iostream>
#include <fstream>
#include "TReceipt.h"







int main() {
	
	TReceipt check;//#CART OF BUYER
	const string path = "C://product_base.txt";
	check.file_reader(path);

	int cash_register_mode = 1;
	int mode = 1;
	int status = 1;
	long product_code;
	int product_num;
	int choice = - 1;
	try {
		do {
			cout << "Welcome to the cash register!" << endl;
			do {
				cout << "Choose an action:" << endl;
				cout << "1. Add a product to the receipt" << "\n"
					<< "2. Change check line" << "\n"
					<< "3. Generate check " << "\n"
					<< "4. End the programme work" << "\n";
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
				case 3:
				{
					check.generate();
					break;
				}
				case 4: mode = 0; break;
				default: throw Exeption<int>(NotFoundCheckMethod, choice);
				}
			} while (mode == 1);

			cout << "Thanks for purchase!Come to our shop again!^^" << endl;
			
			cout << "The next customer?(1/0)" << endl;
			cin >> cash_register_mode;
			if (cash_register_mode != 0 && cash_register_mode != 1) {
				throw Exeption<int>(ValidMode, cash_register_mode);
			}
		} while (cash_register_mode == 1);
	}
	catch(const Exeption<int> ex){
		ex.what();
	}
	catch (const Exeption<long> ex) {
		ex.what();
	}
	
	return 0;
}
