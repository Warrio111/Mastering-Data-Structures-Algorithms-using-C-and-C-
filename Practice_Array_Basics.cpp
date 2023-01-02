#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

	int A[5] = { 2,4,6,7,8 };

	for (int x : A)
	{
		cout << x << endl;
	}


	return 0;
}