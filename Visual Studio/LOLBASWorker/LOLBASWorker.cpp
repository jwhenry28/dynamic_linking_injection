#include <Windows.h> 
#include <iostream>

typedef HRESULT(WINAPI* ENGINEPROC)(DWORD, LPCTSTR, LPCTSTR, DWORD, DWORD);

size_t BUFSIZE = 256;

const wchar_t* CToW(const char* c)
{
    size_t nChars = strlen(c) + 1;

    wchar_t* ws = new wchar_t[nChars];
    char* p = (char*)ws;
    for (int i = 0; i < nChars; i++)
    {
        p[i * 2] = c[i];
        p[i * 2 + 1] = '\0';
    }

    return ws;
}

int main(int argc, const char** argv)
{
    HMODULE hinstLib;
    ENGINEPROC ProcessData{};
    BOOL fRunTimeLinkSuccess = FALSE;
    DWORD ID, operation, mode;
    LPCTSTR title, data;
    HRESULT res;

    try {
        std::string pluginsDir = "Plugins\\";
        std::string pluginName(argv[1]);
        std::string pluginPath = pluginsDir + pluginName;

        hinstLib = LoadLibraryA(pluginPath.c_str());

        if (NULL == hinstLib)
        {
            std::cout << "Failed to load: " << pluginPath << std::endl;
            throw std::invalid_argument("Failed to process.");
        }

        ProcessData = (ENGINEPROC)GetProcAddress(hinstLib, argv[2]);
        if (NULL != ProcessData)
        {
            ID = atol(argv[3]);
            title = CToW(argv[4]);
            data = CToW(argv[5]);
            operation = atol(argv[6]);
            mode = atol(argv[7]);

            res = ProcessData(ID, title, data, operation, mode);
            fRunTimeLinkSuccess = TRUE;
        }

        if (!fRunTimeLinkSuccess)
        {
            std::cout << "Failed to invoke method: " << argv[2] << std::endl;
            throw std::invalid_argument("Failed to process.");
        }
    }
    catch (...) {
        std::cout << "Unable to process data with those arguments." << std::endl;
    }

    return 0;
}