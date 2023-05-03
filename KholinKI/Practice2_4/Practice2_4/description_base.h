#pragma once
#ifndef _DESCRIPTION_BASE_H
#define _DESCRIPTION_BASE_H

#include <string>

using namespace std;

class description_base {
private:
	long code;
	std::string name;
	float cost;
public:
	long get_code() { return code; }
	string get_name() { return name; }
	float get_cost() { return cost; }

	description_base(void);
	void file_read(std::ifstream& file);
};
#endif