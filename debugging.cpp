#include "stdafx.h"


void debug_out(const TCHAR* fmt,...)
{
	#ifdef _DEBUG
	TCHAR buffer[256];
	va_list List;
	va_start(List, fmt);
	_vstprintf(buffer, fmt, List);
	va_end(List);
	//OutputDebugString("@MyApp : "); // 다른 메시지들과 구별하기 위해서
	OutputDebugString(buffer);
	#endif    
}
void debug_out(const TCHAR* filename, const TCHAR* fmt,...)
{
	//#ifdef _DEBUG
	TCHAR filepath[256];
	GetModuleFileName(NULL, filepath, 256);
	_tcscpy(_tcsrchr(filepath, '\\')+sizeof(TCHAR), filename);
	FILE* fp = _tfopen(filepath, TEXT("a"));
	TCHAR buffer[256];
	va_list List;
	va_start(List, fmt);
	_vstprintf(buffer, fmt, List);
	va_end(List);
	//OutputDebugString("@MyApp : "); // 다른 메시지들과 구별하기 위해서
	_ftprintf(fp, TEXT("%s"), buffer);

	fclose(fp);
	//#endif    
    
}


