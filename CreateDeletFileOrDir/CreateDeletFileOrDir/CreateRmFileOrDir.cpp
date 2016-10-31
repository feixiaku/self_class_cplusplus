#include "CreateRmFileOrDir.h"



CreateRmFileOrDir::CreateRmFileOrDir()
{
}


CreateRmFileOrDir::~CreateRmFileOrDir()
{
}

int CreateRmFileOrDir::isExist(const char* _FileName, int _AccessMode)
{
	int num;
	num = _access(_FileName, _AccessMode);
	return num;
}

#if defined (_WIN32)
int CreateRmFileOrDir::createFile(const char* _FileName)
{
	return _mkdir(_FileName);
}
#else
int CreateRmFileOrDir::createFile(const char* _FileName)
{
	return mkdir(_FileName);
}
#endif // defined (_WIN32)

int CreateRmFileOrDir::deletFile(const char* _FileName)
{
	return _rmdir(_FileName);
}

