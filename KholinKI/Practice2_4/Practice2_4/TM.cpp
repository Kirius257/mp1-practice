#include "TM.h"
#include <iostream>
#include <iomanip>
using namespace std;



TM::TM() {
	now = 0;
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
	second = 0;
}

TM::TM(const TM& obj) {
	now = obj.now;
	year = obj.year;
	month = obj.month;
	day = obj.day;
	hour = obj.hour;
	minute = obj.minute;
	second = obj.second;
}


void TM::SET_LOCAL_TIME() {
	//#time_t is a data type in c++ to represent time in seconds from the beginning of the epoch.
//SET SYSTEM TIME WITH FUNCTION time()
	//now - its time.
	now = time(0);
	SAVE(now);
}


void TM::OUTPUT_CLOCK() {
	tm* p = localtime(&now);
	char* dt;
	dt = asctime(p);
	puts(dt);
}

void TM::SAVE(TOKEN now_){
	tm* p = localtime(&now_);
	year = p->tm_year+1900;
	month = p->tm_mon;
	day = p->tm_mday;
	hour = p->tm_hour;
	minute = p->tm_min;
	second = p->tm_sec;
}

const TM& TM::operator=(const TM& obj) {
	now = obj.now; 
	year = obj.year;
	month = obj.month;
	day = obj.day;
	hour = obj.hour;
	minute = obj.minute;
	second = obj.second;
	return *this;
}