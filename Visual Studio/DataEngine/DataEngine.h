#pragma once
#include "pch.h"

#ifdef DATAENGINE_EXPORTS
#define DATAENGINE_API __declspec(dllexport)
#else
#define DATAENGINE_API __declspec(dllimport)
#endif

extern "C" DATAENGINE_API HRESULT ProcessData(DWORD, LPCTSTR, LPCTSTR, DWORD, DWORD);