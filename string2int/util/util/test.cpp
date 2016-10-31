#include "Util.h"
#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char* argv[])
{
	Util util;
	string str_int = "17";
	string str_long = "17000000";
	string str_float = "17.10000";
	string str_null = "";
	cout << " ::::: " << atoi("") << endl;
	cout << "str2int = " << util.string2int(str_null) << endl;
	cout << "str2int = " << util.string2int(str_int) << endl;
	cout << "str2double = "<< setprecision(4) << util.string2double(str_float) << endl;
	cout << "str2double = " << setiosflags(ios::fixed) << util.string2double(str_float) << endl;
	cout << "str2long = "  << util.string2long(str_long) << endl;

	int i = 10;
	long j = 1000000;
	double k = 10.000000;
	cout << "i = " << util.int2string(i) << endl;
	cout << "k = " << util.double2string(k) << endl;
	cout << "j = " << util.long2string(j) << endl;
	return 0;
}