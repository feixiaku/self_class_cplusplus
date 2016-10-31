#include "IOAccess.h"



IOAccess::IOAccess()
{
	this->fileSize = 0;
}


IOAccess::~IOAccess()
{
}

fstream IOAccess::init(string fileName)
{
	assert(fileName != NULL);
	this->fileName = fileName;
	fstream fs;
	fs.open(fileName, ios::out | ios::in | ios::trunc);
	if (!fs.is_open())
	{
		cout << "open " << fileName << " failed" << endl;
	}
	return fs;
}

void IOAccess::writeFile(fstream& file, string str)
{
	cout << "str = " << str << endl;
	//file >> str;
	const char *buf = str.data();
	cout << "length = " << str.length() << endl;
	if (!file.is_open())
	{
		cout << "file is not open" << endl;
		return;
	}
	file.write(buf, str.length());
}

void IOAccess::readFile(fstream& file, int num)
{
	assert(this->countFileSize() >= num && num > 0);
	
	content = new char[num];
	file.getline(content, num);

	//file.read(content, num);
	cout << "num: "<< num<< " content: " << content << endl;
}

int IOAccess::countFileSize(fstream& file)
{
	file.seekg(0, ios::end);
	int num = file.tellg();
	file.seekg(0, ios::beg);
	return num;
}

void IOAccess::seekFile(fstream& file)
{

}

void IOAccess::closeFile(fstream& file)
{
	delete content;
	file.close();
}