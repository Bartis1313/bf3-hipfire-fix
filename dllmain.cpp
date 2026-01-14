#include <Windows.h>

#include "functions.h"
#include "MinHook/include/MinHook.h"

//#include <iostream>

DWORD WINAPI InitThread(LPVOID)
{
    const UINT maxAttempts = 50;
    UINT attempts = 0;
    while (!GetModuleHandleA("dxgi.dll"))
    {
        if (++attempts >= maxAttempts)
        {
            return EXIT_FAILURE;
        }
        Sleep(100);
    }

    MH_Initialize();
    MH_CreateHook((LPVOID)0x11F90F0, (LPVOID)hkfb__WeaponFiring__update, (LPVOID*)&ofb__WeaponFiring__update);
    MH_EnableHook(MH_ALL_HOOKS);

    return EXIT_SUCCESS;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);

    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CloseHandle(CreateThread(nullptr, 0, InitThread, nullptr, 0, nullptr));
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {
        MH_DisableHook(MH_ALL_HOOKS);
        MH_RemoveHook(MH_ALL_HOOKS);
        MH_Uninitialize();
    }

    return TRUE;
}

