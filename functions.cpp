#include "functions.h"

#include "sdk.h"

//#include <iostream>

tfb__WeaponFiring__update ofb__WeaponFiring__update;

void __thiscall hkfb__WeaponFiring__update(fb::WeaponFiring* _this, void* context)
{
	ofb__WeaponFiring__update(_this, context);
	fb::GunSway* p_GunSway = _this->m_weaponSway;

	if (p_GunSway)
	{
		if (p_GunSway->m_dispersionAngle < p_GunSway->m_minDispersionAngle)
		{
			p_GunSway->m_dispersionAngle = p_GunSway->m_minDispersionAngle;

			//printf("patched angle\n");
		}
	}

	if (p_GunSway && p_GunSway->m_isFiring && _this->weaponState <= 3)
	{
		p_GunSway->m_isFiring = false;

		//printf("patched firing\n");
	}
}

//void* __fastcall hkfb__getRecoil(fb::GunSway* _this, void*, unsigned int a2, int a3)
//{
//	if (_this->m_dispersionAngle < _this->m_minDispersionAngle)
//	{
//		_this->m_dispersionAngle = _this->m_minDispersionAngle;
//	}
//
//	return ofb__getRecoil(_this, a2, a3);
//}