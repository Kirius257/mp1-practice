#include "TM.h"
#include <iostream>
#include <iomanip>
using namespace std;

TM::TM(void) {
	p = nullptr;
}

void TM::SYSTEM_C(){
	//#time_t is a data type in c++ to represent time in seconds from the beginning of the epoch.
//SET SYSTEM TIME WITH FUNCTION time()
	time_t now = time(0);

	//now - its time.

	//GET A POINTER TO A STRUCTURE WITH TIME
	p = localtime(&now);
}


void TM::OUTPUT_SYSTEM_C() {
	cout << left
		 << p->tm_hour << ":" << p->tm_min << ":" << p->tm_sec
		 << endl
		 << p->tm_mday << "." << p->tm_mon << "." << 1900+p->tm_year;
	cout << endl << endl << endl;
}