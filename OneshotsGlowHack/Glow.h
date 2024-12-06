#pragma once
#include "includes.h"
#include "Offsets.h"

class Glow
{
public:

	void Runner();
	void Test();
	
	
	void ReadInfo();

	void ReadEntity(int Entnum);

	void GlowEntity(int Entnum);

	void GlowEntitys(int i);

	void SetColor(float r, float g, float b, float a);



	

	




private:

	DWORD LocalTeam = 0;
	DWORD GlowObject = 0;
	DWORD LocalPlayer = 0;
	DWORD Entity = 0;
	DWORD EntityList = 0;
	DWORD Health = 0;
	DWORD IsDormant = 0;
	DWORD GlowIndex = 0;
	DWORD TeamNum = 0;
	DWORD ClassID = 0;
	bool canGlow = false;
	
	enum ClassIDs : int {
		AK47 = 1,
		BaseCSGrenade = 8,
		BaseCSGrenadeProjectile = 9,
		Player = 38,
		C4 = 32,
		Chicken = 34,
		Eagle = 44,
		Decoy = 45,
		DecoyProjectile = 46,
		Flashbang = 75,
		CHEGrenade = 94,
		Hostage = 95,
		HostageCarriableProp = 96,
		IncendiaryGrenade = 97,
		Item_Healthshot = 102,
		MolotovGrenade = 110,
		MolotovProjectile = 111,
		PlantedC4 = 126,
		SensorGrenade = 148,
		SensorGrenadeProjectile = 149,
		SmokeGrenade = 152,
		SmokeGrenadeProjectile = 153,
		WeaponAug = 228,
		WeaponAWP = 229,
		WeaponBizon = 231,
		WeaponElite = 235,
		WeaponFamas = 236,
		WeaponFiveSeven = 237,
		WeaponG3SG1 = 238,
		WeaponGalilAR = 239,
		WeaponGlock = 241,
		WeaponHKP2000 = 242,
		WeaponM249 = 243,
		WeaponM4A1 = 245,
		WeaponMAC10 = 246,
		WeaponMag7 = 247,
		WeaponMP7 = 249,
		WeaponMP9 = 250,
		WeaponNegev = 251,
		WeaponNOVA = 252,
		WeaponP250 = 254,
		WeaponP90 = 255,
		WeaponSawedoff = 256,
		WeaponSCAR20 = 257,
		WeaponSG556 = 261,
		WeaponSSG08 = 262,
		WeaponTaser = 263,
		WeaponTec9 = 264,
		WeaponUMP45 = 266,
		WeaponUSP = 267,
		WeaponXM1014 = 268
	};

};
extern Offsets O;

