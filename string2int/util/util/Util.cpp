#include "Util.h"
#include <assert.h>


Util::Util()
{
	cout << "Util Constructor " << endl;
}


Util::~Util()
{
	cout << "Util destructor " << endl;
}

int Util::string2int(string str)
{
	cout << "size = " << str.size() << endl;
	assert(str.size() < 1);
	if (str.empty())
		exit;
		//return NULL;
	
	int num = 0;
#if defined(_WIN32)
	cout << "string = " << str.c_str() << endl;
	num = atoi((char*)str.data());
#else
	atoi(str.c_str());
#endif // defined(_WIN32)

	return num;
}

long Util::string2long(string str)
{
	if (str.empty())
		return -1;

	long num = 0;
	assert(str.size() != 0);
	num = atol(str.c_str());
	return num;
}

double Util::string2double(string str)
{
	if (str.empty())
		return -1;
	double num = 0;
	assert(str.size() != 0);
	num = atof(str.c_str());
	return num;
}

string Util::int2string(int num)
{
	/*char str[2];
	sprintf_s(str, sizeof(int),"%d", num);
	string s(str);*/
	string s;
	strstream ss;
	ss << num;
	ss >> s;
	return s;
}

string Util::double2string(double num)
{
	char str[10];
	sprintf_s(str, 10, "%lf", num);
	string s(str);
	return s;
}

string Util::long2string(long num)
{
	char str[8];
	sprintf_s(str, 8, "%ld", num);
	string s(str);
	return s;
}