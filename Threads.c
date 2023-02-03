#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX_THREADS 8
#define TAM_MAX 100000

void LoadList(int List[], long size);
DWORD WINAPI SumList(LPVOID arg);

typedef struct {
	int* List;
	long ini, end, sum;
} TdataList;

int main(int argc, char* argv[]) {
	int i, numThreads, List[TAM_MAX];
	long ini, end, sizeList, TotalSum = 0;
	TdataList** params;
	HANDLE HandlerThreads[MAX_THREADS];
	DWORD Threads[MAX_THREADS];

	sizeList = 100000;
	LoadList(List, sizeList);

	numThreads = 4;
	params = (TdataList**)malloc(sizeof(TdataList*));

	for (i = 0; i < numThreads; i++) {
		ini = ((int)sizeList / numThreads) * i;
		end = i < numThreads ? ((int)sizeList / numThreads) * (i + 1) : sizeList;

		params[i] = (TdataList*)malloc(sizeof(TdataList));
		params[i]->List = List;
		params[i]->ini = ini;
		params[i]->end = end;
		params[i]->sum = 0;

		HandlerThreads[i] = CreateThread(NULL, 0, SumList, (LPVOID)params[i], 0, &Threads[i]);
		if (HandlerThreads[i] == NULL) {
			printf("Error al crear el Thread %d\n", i);
			exit(-1);
		}
	}

	WaitForMultipleObjects(numThreads, HandlerThreads, TRUE, INFINITE);

	printf("Termino la ejecucion de los Threads\n");

	for (i = 0; i < numThreads; i++) {
		printf("sum Thread %d: %ld\n", i, params[i]->sum);
		TotalSum += params[i]->sum;
		CloseHandle(HandlerThreads[i]);
	}

	printf("\nsum total: %ld\n", TotalSum);

	return 0;
}

void LoadList(int List[], long size) {
	long i;

	for (i = 0; i < size; i++) {
		List[i] = 1 + rand() % 1000;
	}
}

DWORD WINAPI SumList(LPVOID arg) {
	TdataList* params = (TdataList*)arg;
	int* List = params->List;
	long i, ini, end, * sum;

	ini = params->ini;
	end = params->end;
	sum = &(params->sum);

	for (i = ini; i < end; i++) {
		*sum = *sum + List[i];
	}

	return 0;
}