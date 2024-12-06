#include "Glow.h"

extern CHackProcess fProcess; // Same object thats in OneshotsGlowHack.cpp but we access it in here.
Offsets::GlowStruct EntGlow; // GlowStruct 

void Glow::Runner()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			canGlow = !canGlow;
		}

		if (canGlow == true)
			Test();
		

		Sleep(1);
		
	}
} 

void Glow::Test()
{
	ReadInfo();

		for (int i = 0; i < 200; i++)
		{
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.m_dwGlowObjectManager), &GlowObject, sizeof(int), NULL);
			ReadEntity(i);
			if (Entity)  // ClassID for Player is 38 as of 20/04/2019
			{
				GlowEntitys(i);
			}
		}
	
} 

void Glow::ReadInfo()
{
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.localPlayer), &LocalPlayer, sizeof(int), NULL); // Gets Local Player
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.m_dwGlowObjectManager), &GlowObject, sizeof(int), NULL); // Gets Glow Object
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(LocalPlayer + O.Team), &LocalTeam, sizeof(int), NULL); // Gets LocalTeam 
}

void Glow::ReadEntity(int Entnum)
{
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(GlowObject + 0x38 * Entnum), &Entity, sizeof(Entity), NULL);
	DWORD gBuffer = NULL;
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + 0x8), &gBuffer, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(gBuffer + 0x8), &gBuffer, sizeof(int), NULL);  // This chunk here 'creates' ClassID for object
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(gBuffer + 0x1), &gBuffer, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(gBuffer + 0x14), &ClassID, sizeof(int), NULL);

	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + O.Team), &TeamNum, sizeof(int), NULL);// Getting the entitys Team Number
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + O.Health), &Health, sizeof(int), NULL); // Getting the entitys Health
}

void Glow::GlowEntity(int Entnum)
{
	if (Entity && LocalPlayer)
	WriteProcessMemory(fProcess.__HandleProcess, (PBYTE*)(GlowObject + 0x38 * Entnum + 0x4), &EntGlow, sizeof(EntGlow), NULL);
}

void Glow::GlowEntitys(int i)
{
		switch (ClassID)
		{
		case AK47:
			SetColor(1.f, 0.3f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case BaseCSGrenade:
			SetColor(1.f, 0.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case BaseCSGrenadeProjectile:
			SetColor(1.f, 0.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case Player: //
			if (LocalTeam != TeamNum || GetKeyState(VK_F5) == 1) {
				SetColor((1.f - (Health * 0.01f)), Health * 0.01f, 0.f, 0.8f);
				GlowEntity(i);
			}
			else {
				SetColor(0.f, 0.f, 1.f, 0.8f);
				GlowEntity(i);
			}
			break;
		case C4:
			SetColor(1.f, 0.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case Eagle:
			SetColor(0.f, 1.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case Decoy:
			SetColor(1.f, 1.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case DecoyProjectile:
			SetColor(1.f, 1.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case Flashbang:
			SetColor(1.f, 0.f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case CHEGrenade:
			SetColor(1.f, 0.f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case Hostage:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case HostageCarriableProp:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case IncendiaryGrenade:
			SetColor(1.f, 1.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case Item_Healthshot:
			SetColor(0.f, 1.f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case MolotovGrenade:
			SetColor(1.f, 1.f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case MolotovProjectile:
			SetColor(1.f, 1.f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case PlantedC4:
			SetColor(0.f, 1.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case SensorGrenade:
			SetColor(0.f, 1.f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case SensorGrenadeProjectile:
			SetColor(0.f, 1.f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case SmokeGrenade:
			SetColor(0.f, 1.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case SmokeGrenadeProjectile:
			SetColor(0.f, 1.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponAug:
			SetColor(0.f, 1.f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponAWP:
			SetColor(0.f, 1.0f, 0.2f, 1.f);
			GlowEntity(i);
			break;
		case WeaponBizon:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponElite:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponFamas:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponFiveSeven:
			SetColor(0.f, 1.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponG3SG1:
			SetColor(1.f, 0.3f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponGalilAR:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponGlock:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponHKP2000:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponM249:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponM4A1:
			SetColor(1.f, 1.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponMAC10:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponMag7:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponMP7:
			SetColor(1.f, 1.0f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponMP9:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponNegev:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponNOVA:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponP250:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponP90:
			SetColor(1.f, 1.f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponSawedoff:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponSCAR20:
			SetColor(1.f, 0.3f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponSG556:
			SetColor(0.f, 1.f, 0.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponSSG08:
			SetColor(1.f, 0.3f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponTaser:
			SetColor(1.f, 1.f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponTec9:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponUMP45:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponUSP:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		case WeaponXM1014:
			SetColor(0.f, 0.0f, 1.f, 1.f);
			GlowEntity(i);
			break;
		default:
			break;
		}
	}

void Glow::SetColor(float r, float g, float b, float a) { // setting the glow color
	EntGlow.red = r; EntGlow.green = g; EntGlow.blue = b; EntGlow.alpha = a;
}



