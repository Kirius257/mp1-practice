#include <iostream>
#include <fstream>
#include "TReceipt.h"
#include "Base.h"
#include "Shop.h"
#include <iomanip>



//strings of code: 1046

int main() {
	Shop checks;
	Base data;

	int zero = 0;
	int cash_register_mode = 1;
	int mode = 1;
	int status = 1;
	int flag = 1;
	long product_code;
	int product_num;
	int choice = - 1;
	try {
		do {
			while (flag == 1) {
				TReceipt check;//#CART OF BUYER
				cout << "Welcome to the cash register!" << endl;
				do {
					cout << "Choose an action:" << endl;
					cout << "1. Add a product to the receipt" << "\n"
						 << "2. Change check line" << "\n"
						 << "3. Show cart" << "\n"
						 << "4. Generate check " << "\n";
					cin >> choice;

					switch (choice)
					{
					case 1:
					{
						TRecipline buying;
						int counter_num = 1;
						int index;
						do {
						
							do {

								cout << "Input four-digits code: " << endl;
								cin >> product_code;
								buying.product.set_code(product_code);
								index = data.scanner(product_code);
								if(index == -1)throw Exeption<long>(NotFoundElement, product_code);
								else cout << "Product found!" << endl;

								cout << "How much product do you need?" << endl;
								cin >> product_num;
								buying.num = product_num;
								do {
									if (data.zero_check(buying) == true) {
										zero = 1;
										break;
									}
									else zero = 0;
									if (data < buying) {
										
										cout << "You have entered too many items!" << endl;
										cout << "Input again:" << endl;
										cin >> product_num;
										buying.num = product_num;
									}
								} while ((data < buying) == true);
								if (zero == 0) {
									counter_num = 0;
								}
								else cout << "The product with the code " << product_code << " is out!" << endl;

							}while (counter_num == 1);
							
							
								
								
								buying.product = data.get_product(index);
								buying.sum = buying.product.get_cost() * buying.num;
								
							
							
							if (check == buying) {
								data.control(buying);
							}
							else data.control(buying);
							

							check.add_product(buying);
							cout << "Continue?(1/0)" << endl;
							cin >> status;
							counter_num = 1;
							if (status != 1 && status != 0) {
								throw Exeption<int>(ValidChoice, choice);
							}
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
						
						cout << check << endl; break;
						
					}
					case 4:
					{
						cout << "CHECK #" << checks.get_num() << endl;
						check.generate();
						checks.add(check);
						cout << endl << endl << endl
							<< "Thanks for purchase!Come to our shop again!^^"
							<< endl
							<< endl;
							
						mode = 0;
						break;
					}
					default: throw Exeption<long>(NotFoundCheckMethod, choice);
					}
				} while (mode == 1);
				mode = 1;
				cout << "SYSTEM MESSAGE: serve the next customer?(1/0)"
				<< endl
				<< endl
				<< endl;
				cin >> flag;
				if (flag == 1) {
					break;
				}
			}
			if (flag == 0) {
				cash_register_mode = 0;
			}
		} while (cash_register_mode == 1);
		cout << "Show all checks?(1/0)" << endl;
		cin >> choice;
		if (choice == 1) {
			
			cout << checks << endl;
		}
		else;;
	}
	catch(const Exeption<int> ex){
		ex.what();
	}
	catch (const Exeption<long> ex) {
		ex.what();
	}
	
	return 0;
}