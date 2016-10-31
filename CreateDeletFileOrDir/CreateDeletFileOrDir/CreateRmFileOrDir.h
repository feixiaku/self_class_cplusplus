#pragma once

#if defined (_WIN32)
#include <io.h> //is exit access(const char* filename, int _AccessMode)
#include <direct.h> //mkdir(const char* _Path)
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif // 0



class CreateRmFileOrDir
{
public:
	CreateRmFileOrDir();
	~CreateRmFileOrDir();
public:
	int isExist(const char* _FileName, int _AccessMode);
	int deletFile(const char* _FileName);
#if defined (_WIN32)
int createFile(const char* _FileName);
#else
int createFile(const char* _FileName, int mode_t mode);
#endif

};

