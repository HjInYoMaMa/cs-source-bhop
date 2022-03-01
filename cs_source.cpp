#include <iostream>
#include <Windows.h>

DWORD pid;
DWORD Bunnyhop = 0x0B4FD7D4;
DWORD Forcejump = 0x21665D24;
int fj;
int value;

int main()
{
	HWND hwnd = FindWindowA(0, ("Counter-Strike Source"));

	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	for(;;)
	{

	ReadProcessMemory(pHandle, (void*)Bunnyhop, &value, sizeof(value), 0);

	if (GetAsyncKeyState(VK_SPACE) && value == 257)
	{
		fj = 5;
		WriteProcessMemory(pHandle, (LPVOID)Forcejump, &fj, sizeof(int), 0);
	}
	else
	{
		fj = 4;
		WriteProcessMemory(pHandle, (LPVOID)Forcejump, &fj, sizeof(int), 0);
	}
  }
}