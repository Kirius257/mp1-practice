#include <iostream>
#include <fstream>
#include "TReceipt.h"
#include "TContainer.h"
#include "product_base.h"

using namespace std;


int main() {
	const string path = "C://product_base.txt";

	TContainer products;//create massive products
	
	product_base DATA(path);


	cout << "Welcome to our shop!Chooce products and enter four-digits codes: " << endl;
	int status = 0;
	int choice = 1;
	long code;
	do {
		cin >> code;
		status = DATA.scanner1_0(code);
		if (status == 1) {
			
			
			cout << "Scanning successfully!" << endl;

			cout << "Specify the quantity of the product: " << endl;
			int num;
			cin >> num;
			

			cout << "Continue ? (1 / 0)" << endl;
			cin >> choice;
		}
		else cout << "Product with code " << code << " not found!" << endl;
	} while (choice == 1);
	return 0;
}
