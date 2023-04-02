#include "pch.h"
#include "DataEngine.h"
#include "sha256.h"
#include "windows.h"
#include "string.h"
#include <string>

#define OPERATION_HASH 0

/* ProcessData
	id			- ID of the data node (numerical, sequential integer)
	nodeName	- human-readable name for the node
	data		- The XML data of the node
	status		- Which item to extract from the node

	ProcessData takes in the above parameters, and, based on status, 
	does the following:
	- OPERATION_HASH: Hashes all data together
*/
HRESULT ProcessData(DWORD id, LPCTSTR nodeName, LPCTSTR data, DWORD operation, DWORD mode)
{
	wchar_t outputClear[256];
	swprintf(outputClear, 256, L"%d:%s:%s:%d:%d", id, nodeName, data, operation, mode);
	std::wcout << outputClear << std::endl;

	SHA256 sha256;
	std::wstring ws(outputClear);
	std::string hashString(ws.begin(), ws.end());
	std::cout << sha256(hashString) << std::endl;
	return S_OK;
}