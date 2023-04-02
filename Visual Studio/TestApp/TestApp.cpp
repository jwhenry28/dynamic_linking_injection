#include <windows.h> 
#include <stdio.h> 

typedef DWORD(__cdecl* MYFUNC)();

int main(void)
{
    HMODULE hModule;
    MYFUNC funcPtr{};
    BOOL loadRes, freeRes = FALSE;

    // Load DLL
    hModule = LoadLibraryA("EvilDLL.dll");

    // Import function
    if (hModule)
    {
        funcPtr = (MYFUNC)GetProcAddress(hModule, "TestMethod");

        // Invoke the function
        if (funcPtr)
        {
            loadRes = TRUE;
            (funcPtr)();
        }

        // Free the library module.
        freeRes = FreeLibrary(hModule);

        if (!freeRes)
            printf("Failed to free library.\n");
    }

    return 0;
}