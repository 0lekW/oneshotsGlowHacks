#include "Triggerbot.h"
#include "MemMan.h"

extern CHackProcess fProcess;
Offsets O;
MemMan MemClass;

void Trigger::Run()
{
	bool canTBot = false;
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.localPlayer), &LocalPlayer, sizeof(int), NULL); // Gets Local Player

	if (LocalPlayer == NULL)
		while (LocalPlayer == NULL)
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.localPlayer), &LocalPlayer, sizeof(int), NULL); // Gets Local Player
	
	while (true)
	{
		if (GetAsyncKeyState(VK_F2) & 1)
		{
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(LocalPlayer + O.Team), &LocalTeam, sizeof(int), NULL); // Gets LocalTeam 
			canTBot = !canTBot;
		}

		if (canTBot)
			handleTBot();

		Sleep(1);
	}
}


struct variables
{
	DWORD strangeLocalPlayer;
	DWORD gameModule;
	int myTeam;
	int tbDelay;
	int myWeaponID;
} val;

struct vector
{
	float x, y, z;
};


float Trigger::getDistance(DWORD specialEntity)
{
	int proc = MemClass.getProcess("csgo.exe");
	val.gameModule = MemClass.getModule(proc, "client_panorama.dll");
	val.strangeLocalPlayer = MemClass.readMem<DWORD>(val.gameModule + O.localPlayer);
	vector myLocation = MemClass.readMem<vector>(val.strangeLocalPlayer + O.vectorOrigin);
	vector enemyLocation = MemClass.readMem<vector>(specialEntity + O.vectorOrigin);

	return sqrt(pow(myLocation.x - enemyLocation.x, 2) + pow(myLocation.y - enemyLocation.y, 2) + pow(myLocation.z - enemyLocation.z, 2)) * 0.0254;
}

void Trigger::getMyWeapon()
{
	int proc = MemClass.getProcess("csgo.exe");
	val.gameModule = MemClass.getModule(proc, "client_panorama.dll");
	val.strangeLocalPlayer = MemClass.readMem<DWORD>(val.gameModule + O.localPlayer);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(val.strangeLocalPlayer + O.activeWeapon), &weapon, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(val.gameModule + O.EntityList + (((weapon & 0xFFF) - 1) * 0x10)), &weaponEntity, sizeof(int), NULL);
	if (weaponEntity != NULL)
		val.myWeaponID = MemClass.readMem<int>(weaponEntity + O.itemDefIndex);
	 // std::cout << val.myWeaponID << std::endl; // THIS IS IMPORTANT PLEASE USE TO FIND IDS SCHOOL OLEK - JUST AIM WITH WEAPON OF CHOICE!!
}

bool Trigger::checkIfScoped()
{
	return MemClass.readMem<bool>(val.strangeLocalPlayer + O.isScoped);
}

void Trigger::setTBDelay(float distance)
{
	float delay;
	switch (val.myWeaponID)
	{
	case 262204: delay = 3; break;
	case 7: delay = 3.3; break;
	case 40: delay = 0.15; break;
	case 9: delay = 0.15; break;

	default: delay = 0;
	}
	val.tbDelay = delay * distance;
}

void Trigger::handleTBot()
{
	if (checkTBot())
		shoot();
}

bool Trigger::checkTBot()
{
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(LocalPlayer + O.Crosshair), &Crosshair, sizeof(int), NULL); // Gets Crosshair
	if (Crosshair != 0 && Crosshair < 64)
	{
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.EntityList + ((Crosshair - 1) * 0x10)), &specialEntity, sizeof(specialEntity), NULL);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(specialEntity + O.Team), &eTeam, sizeof(int), NULL);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(specialEntity + O.Health), &specialeHealth, sizeof(int), NULL);
		if (eTeam != LocalTeam && specialeHealth > 0)
		{
			float distance = getDistance(specialEntity);
			getMyWeapon();
			setTBDelay(distance);
			if (val.myWeaponID == 40 || val.myWeaponID == 9)
				return checkIfScoped();
			else
				return true;
		}
		else
			return false;
	}
	else
		return false;
}

void Trigger::shoot()
{
	/*WriteProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.ForceLMB), &ShootTing, sizeof(int), 5); // Alot of testing was done in this commented but to try and write to 5 using offset.
	BOOL WriteProcessMemory(HANDLE  hProcess, LPVOID  lpBaseAddress, LPCVOID lpBuffer, SIZE_T  nSize, SIZE_T * lpNumberOfBytesWritten); //Code given from oneshot
	
	
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL); // These mouse events WORK. But are not used.
	Sleep(20);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL); */ 
	Sleep(val.tbDelay);
	ShootTing = 5;
	WriteProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.ForceLMB), &ShootTing, sizeof(ShootTing), NULL);
	Sleep(20);
	ShootTing = 4;
	WriteProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.ForceLMB), &ShootTing, sizeof(ShootTing), NULL);

}


