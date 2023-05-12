#include <iostream>
#include <fstream>
#include "TReceipt.h"

#define NUM_CONTAINERS 2

using namespace std;


int main() {
	const string path = "C://product_base.txt";
	TReceipt check(NUM_CONTAINERS,path);
	
	return 0;
}
