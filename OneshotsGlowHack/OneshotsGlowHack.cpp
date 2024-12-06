#include "includes.h"
CHackProcess fProcess;
Trigger T;
int main()
{
	std::cout << "Oleks Cheats" << std::endl;
	std::cout << "Press F1 to toggle ESP" << std::endl;
	std::cout << "Press F2 to toggle Triggerbot" << std::endl;
	fProcess.RunProcess();

	while (true)
	{
		T.Run();
		Sleep(1);
	}
	

	return 0;
}