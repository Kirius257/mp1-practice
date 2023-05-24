#pragma once
#ifndef _TM_H
#define _TM_H
#include <ctime>


struct TM {
	tm* p;

	TM(void);
	void SYSTEM_C();
	void OUTPUT_SYSTEM_C();
};

#endif