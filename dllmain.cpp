#include <Windows.h>

#include "functions.h"
#include <MinHook.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);

    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        MH_Initialize();
        MH_CreateHook((LPVOID)0x11F90F0, hkfb__WeaponFiring__update, (LPVOID*)&ofb__WeaponFiring__update);
        MH_EnableHook((LPVOID)0x11F90F0);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {
        MH_DisableHook(MH_ALL_HOOKS);
        MH_RemoveHook(MH_ALL_HOOKS);
        MH_Uninitialize();
    }

    return TRUE;
}

