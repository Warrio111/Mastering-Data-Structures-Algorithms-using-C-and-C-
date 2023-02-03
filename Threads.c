#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

DWORD WINAPI Display(LPVOID arg);


int main(int arg, char* argv[])
{
	HANDLE hHandler, hHandler2;
	DWORD Thread, Thread2;
	HRESULT hr;

	hHandler = CreateThread(NULL, 0, Display, (LPVOID)1, 0, &Thread);
	hHandler2 = CreateThread(NULL, 0, Display, (LPVOID)11, 0, &Thread2);

	if (hHandler == NULL || hHandler2 == NULL)
	{
		printf("Threads are created in a wrong way");
		exit(-1);
	}
	printf("Threads creation SUCCEEDED\n");
	WaitForSingleObject(hHandler, INFINITE);
	WaitForSingleObject(hHandler2, INFINITE);
	printf("Threads finished all the work");
	CloseHandle(hHandler);
	CloseHandle(hHandler2);

	return 0;
}

DWORD WINAPI Display(LPVOID arg)
{
	int i;
	int ini;
	ini = (int)arg;
	for (i = ini; i < ini + 10; i++)
	{
		if (ini == 1)
		{
			Sleep(1000 + rand() % 5000);
		}
		else
		{
			Sleep(5000 + rand() % 5000);
		}
		printf("%d\n", i);
	}

	return 0;
}