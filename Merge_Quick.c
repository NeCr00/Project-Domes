#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void print(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d  ", array[i]);
	printf("\n");
}
void merging(int array[], int low1, int high1, int low2, int high2)
{
	int temp[10000];
	int i, j, k;
	i = low1;
	j = low2;
	k = 0;

	while (i <= high1 && j <= high2)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= high1)
		temp[k++] = array[i++];

	while (j <= high2)
		temp[k++] = array[j++];

	for (i = low1, j = 0; i <= high2; i++, j++)
		array[i] = temp[j];
}

void mergesort(int array[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(array, low, mid);
		mergesort(array, mid + 1, high);
		merging(array, low, mid, mid + 1, high);
	}
	else
	{
		return;
	}
}

void QuickSort(int array[], int left, int right)
{
	int pivot, leftArrow, rightArrow;
	leftArrow = left;
	rightArrow = right;
	pivot = array[(left + right) / 2];
	do
	{
		while (array[rightArrow] > pivot)
			--rightArrow;
		while (array[leftArrow] < pivot)
			++leftArrow;
		if (leftArrow <= rightArrow)
		{	
			int temp = array[leftArrow];
			array[leftArrow] = array[rightArrow];
			array[rightArrow] = temp;
			
			++leftArrow;
			--rightArrow;
		}
	} while (rightArrow >= leftArrow);
	if (left < rightArrow)
		QuickSort(array, left, rightArrow);
	if (leftArrow < right)
		QuickSort(array, leftArrow, right);
}
int main()
{
	//======================================================
	// dhmiourgia pinaka kai tou antigrafou
	int array[10000], size = 10000;
	int i;
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % 1000 + 1;
	}
	int temp[5000];

	memcpy(temp, array, sizeof(array));

	//==================Merge Sort===========================
	double time;
	clock_t start, end;
	start = clock();
	mergesort(temp, 0, size - 1);
	end = clock();
	time = ((double)(end - start)) / CLK_TCK;
	printf("Total time of Merge Sort execution is %.15lf\n", time);
	//========================================================

	memcpy(temp, array, sizeof(array));

	//===================Quick Sort===========================
	start = clock();
	QuickSort(temp, 0, size - 1);
	end = clock();
	time = ((double)(end - start)) / CLK_TCK;
	printf("Total time of Quick Sort execution is %.15lf\n", time);
	//=========================================================
	return 0;
}