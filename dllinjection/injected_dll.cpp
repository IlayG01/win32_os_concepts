#include "pch.h"
#define DLL_EXPORT
#include "injected_dll.h"

#define MSG ("Hacked By 1l4yG")

extern "C"
{
	DECLDIR void Pop()
	{
		int msgBoxID = MessageBoxA(NULL,
			(LPCSTR)MSG,
			(LPCSTR)MSG,
			MB_DEFBUTTON2);
	}
}
BOOL APIENTRY DllMain(HANDLE hModule, // Handle to DLL module
	DWORD ul_reason_for_call,
	LPVOID lpReserved) // Reserved
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// A process is loading the DLL.
		Pop();
		break;
	case DLL_THREAD_ATTACH:
		// A process is creating a new thread.
		break;
	case DLL_THREAD_DETACH:
		// A thread exits normally.
		break;
	case DLL_PROCESS_DETACH:
		// A process unloads the DLL.
		break;
	}
	return TRUE;
}
