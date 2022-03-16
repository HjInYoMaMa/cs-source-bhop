#include <iostream>
#include <Windows.h>

DWORD pid;
DWORD Bunnyhop = 0x6969; //Put here newer offset lmao
DWORD Forcejump = 0x1337; //Put here newer offset lmao
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
