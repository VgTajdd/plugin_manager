#include <Windows.h>
#include <iostream>

// https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain

BOOL APIENTRY DllMain( HINSTANCE hInst,
					   DWORD reason,
					   LPVOID reserved )
{
	switch ( reason )
	{
		case DLL_PROCESS_ATTACH:
			std::cout << "[DllMain] DLL attached to process." << std::endl;
			break;
		case DLL_PROCESS_DETACH:
			std::cout << "[DllMain] DLL detached to process." << std::endl;
			break;
		case DLL_THREAD_ATTACH:
			std::cout << "[DllMain] DLL attached to thread." << std::endl;
			break;
		case DLL_THREAD_DETACH:
			std::cout << "[DllMain] DLL detached to thread." << std::endl;
			break;
	}
	return TRUE;
}