#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

void attackerMethod()
{
    const char* outfileName = "C:\\Users\\Public\\info.txt";
    DWORD pid = GetCurrentProcessId();
    char username[64];
    DWORD username_len = 64;
    GetUserNameA((LPSTR)username, &username_len);

    std::string infoMessage = "Username: " + std::string(username) + "\n";
    infoMessage += "Process ID: " + std::to_string(pid) + "\n";

    std::ofstream outfile;
    outfile.open(outfileName);
    outfile << infoMessage;
    outfile.close();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
        //attackerMethod();
        break;
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

