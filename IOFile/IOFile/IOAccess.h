#pragma once

#include <iostream>
#include <istream>
#include <fstream>
#include <assert.h>
#include <string>
using namespace std;

class IOAccess
{
public:
	int fileSize;
	string fileName;
	fstream file;
	char *content;
	IOAccess();
	~IOAccess();

public:
	fstream init(string fileName);
	void readFile(fstream& pFile, int num);
	void writeFile(fstream& pFile, string str);
	int countFileSize(fstream& pFile);
	void seekFile(fstream& pFile);
	void closeFile(fstream& pfile);
};

