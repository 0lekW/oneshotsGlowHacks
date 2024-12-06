#pragma once
#include "includes.h"

class Offsets
{
public:



	DWORD localPlayer = 0xCEA95C;
	DWORD EntityList = 0x4CFC35C;
	DWORD Team = 0xF4;
	DWORD Health = 0x100;
	DWORD EntLoopDist = 0x10;
	DWORD Crosshair = 0xB3AC; // No
	DWORD ForceLMB = 0x312DA5C; // Yes \x89\x0D\xCC\xCC\x8B\x0D\xCC\xCC\x8B\xF2\x8B\xC1\x83\xCE\x04 xx??xx??xxxxxxx
	DWORD vectorOrigin = 0x138; // No
	DWORD itemDefIndex = 0x2FAA; // No
	DWORD activeWeapon = 0x2EF8; // No
	DWORD isScoped = 0x3910; // No
	DWORD m_iGlowIndex = 0xA40C; // No
};