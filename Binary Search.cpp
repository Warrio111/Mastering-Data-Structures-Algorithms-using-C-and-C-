#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Array
{
	int A[10];
	int size;
	int length;
};
void Display(struct Array* arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < (*arr).length; i++)
	{
		printf("%d ", arr->A[i]);
	}
}
void Append(struct Array* arr, int x)
{
	if (arr->length < arr->size)
	{
		arr->A[arr->length++] = x;
	}
}
void Insert(struct Array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];

		}
		arr->A[index] = x;
		arr->length++;
	}
}
int Delete(struct Array* arr, int index)
{
	int i;
	int x = 0;
	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
		return x;
	}
	return 0;
}
void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int LinearSearch(struct Array* arr, int key)
{
	int i;

	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[i - 1]);
			return i;
		}
	}

	return -1;
}
int BinSearch(struct Array arr, int key)
{
	int l;
	int mid;
	int h;
	l = 0;
	h = arr.length - 1;
	for (; l <= h;)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
		{
			return mid;
		}
		else if (key < arr.A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}

	}

	return -1;
}
int RBinSearch(int a[], int l, int h, int key)
{
	int mid;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
		{
			return mid;
		}
		else if (key < a[mid])
		{
			return RBinSearch(a, l, mid - 1, key);
		}
		else
		{
			return RBinSearch(a, mid + 1, h, key);
		}
	}

	return -1;
}
int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
	{
		return arr.A[index];
	}
	return -1;
}
void Set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
	{
		arr->A[index] = x;
	}
}
int Max(struct Array arr)
{
	int max;
	int i;
	max = arr.A[0];
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}
	return max;
}
int Min(struct Array arr)
{
	int min;
	int i;
	min = arr.A[0];
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}
	return min;
}
int Sum(struct Array arr)
{
	int sum;
	sum = 0;
	int i;
	for (i = 0; i < arr.length; i++)
	{
		sum += arr.A[i];

	}
	return sum;
}
float Avg(struct Array arr)
{
	return (float)(Sum(arr) / arr.length);
}

void Reverse(struct Array* arr)
{
	int* B;
	int i;
	int j;
	B = (int*)malloc(arr->length * sizeof(int));
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];

	}
	for (i = 0; i < arr->length; i++)
	{
		arr->A[i] = B[i];
	}

}

void Reverse2(struct Array* arr)
{
	int i;
	int j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}
}

void InsertSort(struct Array* arr, int x)
{
	int i;
	i = arr->length - 1;
	if (arr->length == arr->size)
	{
		return;
	}
	while (arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;

}
int isSorted(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
		{
			return 0;
		}
	}
	return 1;
}
void REarrange(struct Array* arr)
{
	int i;
	int j;
	i = 0;
	j = arr->length - 1;
	while (i < j)
	{
		while (arr->A[i] < 0) { i++; }
		while (arr->A[j] >= 0) { j--; }
		if (i < j) { swap(&arr->A[i], &arr->A[j]); }

	}
}
void Ordenar(struct Array* arr)
{
	float t;
	int i, j;

	for (i = 1; i < arr->length; i++)
	{
		j = i - 1;
		t = arr->A[i];
		while (j >= 0 && t < arr->A[j])
		{
			arr->A[j + 1] = arr->A[j];
			j = j - 1;
		}
		arr->A[j + 1] = t;
	}


}
int main()
{

	struct Array arr = { {2,-3,4,-10,16},10,5 };

	Ordenar(&arr);
	Display(&arr);


	return 0;
}