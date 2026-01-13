#pragma once

namespace fb
{
	class WeaponFiring
	{
	public:
		char pad[0xA0];
		class GunSway* m_weaponSway;
		int weaponState; // enum
	};

	struct WeaponSway
	{
		void* callback;
	};

	class GunSway : public WeaponSway
	{
	public:
		struct Deviation
		{
			float m_pitch;
			float m_yaw;
			float m_roll;
			float m_transY;
		};

		const void* m_data; // 0x004 (GunSwayData*)
		// eastl::list<fb::GunSwayModifierData const*, ...>
		char m_modifierData[0x0C];// 0x008
		// eastl::fixed_list<fb::GunSway::PoseTransition, 2, 1, ...>
		char m_transitionList[0x98];                           // 0x014
		Deviation m_currentRecoilDeviation;                    // 0x0AC
		float m_timeSinceLastShot;                             // 0x0BC
		// fb::ScopedPtr<fb::GunSway::CameraRecoilDeviation>
		void* m_cameraRecoilDeviation;                         // 0x0C0
		char pad_00C4[0x0C];                                   // 0x0C4
		// fb::LinearTransform
		char m_cameraRecoilTransform[0x40];                    // 0x0D0
		Deviation m_currentLagDeviation;                       // 0x110
		float m_dispersionAngle;                               // 0x120
		float m_minDispersionAngle;                            // 0x124
		float m_crossHairDispersionFactor;                     // 0x128
		Deviation m_currentDispersionDeviation;                // 0x12C
		float m_currentGameplayDeviationScaleFactor;           // 0x13C
		float m_currentVisualDeviationScaleFactor;             // 0x140
		float m_suppressionMinDispersionAngleFactor;           // 0x144
		// fb::Random
		char m_random[0x10];                                   // 0x148
		unsigned int m_seed;                                   // 0x158
		float m_randomAngle;                                   // 0x15C
		float m_randomRadius;                                  // 0x160
		bool m_fireShot;                                       // 0x164
		char pad_0165[0x03];                                   // 0x165
		unsigned int m_initialFireShot;                        // 0x168
		bool m_isFiring;                                       // 0x16C
	};
}