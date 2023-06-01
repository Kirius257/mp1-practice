#pragma once
#ifndef _TM_H
#define _TM_H
#include <ctime>

class TM {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	time_t now;
public:
	TM(void);
	TM(const TM& obj);

	void SET_LOCAL_TIME();
	void OUTPUT_CLOCK();
	void SAVE(time_t now_);

	const TM& operator=(const TM& obj);
};
#endif