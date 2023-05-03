#pragma once
#ifndef _PRODUCT_BASE_H
#define _PRODUCT_BASE_H


#include "description_base.h"
#include <string>




enum class FileExeption { NullPtrFile = -1 };
class product_base {
private:
	int count;
	description_base* d_base;
public:
	product_base(const std::string& path);
	~product_base();

	int scanner1_0(long& code);
};

#endif