#pragma once

namespace fb
{
	class WeaponFiring;
	class GunSway;
}

typedef void(__thiscall* tfb__WeaponFiring__update)(fb::WeaponFiring* _this, void* context);
extern tfb__WeaponFiring__update ofb__WeaponFiring__update;
void __thiscall hkfb__WeaponFiring__update(fb::WeaponFiring* _this, void* context);

//typedef void* (__thiscall* tfb__getRecoil)(fb::GunSway* _this, unsigned int a2, int a3);
//inline tfb__getRecoil ofb__getRecoil = 0;
//void* __fastcall hkfb__getRecoil(fb::GunSway* _this,void*, unsigned int a2, int a3);