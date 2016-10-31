#include "IOAccess.h"
#include <iostream>     // std::cout
#include <fstream>      // std::fstream

using namespace std;

int main()
{
	IOAccess ioAccess;
	fstream testFile;
	//create file
	testFile = ioAccess.init("test.txt");
	if (!testFile.is_open())
	{
		cout << "testFile open failed" << endl;
		return -1;
	}

	//write data to the file
	ioAccess.writeFile(testFile, "this is a test file!");

	//compute the file's size
	ioAccess.fileSize = ioAccess.countFileSize(testFile);
	cout << "fileSize " << ioAccess.fileSize << endl;
	
	//read file to verify
	ioAccess.readFile(testFile, ioAccess.fileSize);
	cout << "file content: " << ioAccess.content << endl;
	//close file
	ioAccess.closeFile(testFile);

	return 0;
}

