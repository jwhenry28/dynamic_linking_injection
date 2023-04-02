#pragma once

#ifdef EVILDLL_EXPORTS
#define EVILDLL_API __declspec(dllexport)
#else
#define EVILDLL_API __declspec(dllimport)
#endif

#include "pch.h"

extern "C" EVILDLL_API DWORD AttackerMethod(DWORD, LPCWSTR, LPCWSTR, DWORD, DWORD);

extern "C" EVILDLL_API DWORD TestMethod();