#pragma once
#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <strstream>
#include <iostream>

using namespace std;

class Util
{
public:
	Util();
	~Util();
public:
	//trans string into int/long/double
	int string2int(string str);
	long string2long(string str);
	double string2double(string str);
	//trans int/long/double into string
	string int2string(int num);
	string long2string(long num);
	string double2string(double num);
};

#endif // !



