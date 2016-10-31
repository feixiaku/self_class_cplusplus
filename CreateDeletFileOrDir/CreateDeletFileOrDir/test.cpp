#include <iostream>
#include "CreateRmFileOrDir.h"

using namespace std;

int main()
{
	CreateRmFileOrDir mCreateRmFileOrDir;
	string str = "./test";

	if (mCreateRmFileOrDir.isExist(str.c_str(), 0) != 0)
	{
		if (mCreateRmFileOrDir.createFile(str.c_str()) != 0)
		{
			cout << "creat file failed" << endl;
		}
		else 
		{
			if (mCreateRmFileOrDir.deletFile(str.c_str()) != 0)
			{
				cout << "delete file error" << endl;
			}
		}
	}
	else
	{
		cout << "dir exist" << endl;
		if (mCreateRmFileOrDir.deletFile(str.c_str()) != 0)
		{
			cout << "delete file error" << endl;
		}
	}
	return 0;
}