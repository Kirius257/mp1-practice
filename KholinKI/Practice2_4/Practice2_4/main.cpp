#include <iostream>
#include <fstream>
#include "TReceipt.h"


#define NUM_CONTAINERS 2
#define MAX_SIZE 3
#define STEP 10


using namespace std;


int main() {
	const string path = "C://product_base.txt";
	TReceipt check(NUM_CONTAINERS);//#CART OF BUYER
	TContainer<Pair>my_base(MAX_SIZE,STEP,path);//#BASE OF PRODUCT

	
	return 0;
}
