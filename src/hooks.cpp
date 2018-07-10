#include "../include/hooks.h"
#include "../include/rpc.h"

template <class T> void hook(ULONG_PTR address, T value) {
    DWORD oldProtect = 0;
    VirtualProtect(LPVOID(address), sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);

    *(T*)address = value;
    VirtualProtect(LPVOID(address), sizeof(T), oldProtect, NULL);
}

namespace zString {
	char* (__thiscall *ToChar)(void*) = reinterpret_cast<__thiscall char*(*)(void*)>(0x4639D0);
}

namespace oCGame {
	void (__thiscall *LoadWorldStartup)(void*, void*) = reinterpret_cast<__thiscall void(*)(void*, void*)>(0x6C9C10);

	void __thiscall LoadWorldStartup_Hook(void *self, void* zen) {
		char* zenFile = zString::ToChar(zen);

		updatePresenceDetails(zenFile);

		LoadWorldStartup(self, zen);
	}
}

void createHooks () {
	hook(0x83C338, oCGame::LoadWorldStartup_Hook);
}
