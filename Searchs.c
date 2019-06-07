#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void linsearch(int array[], int x, int n)
{

    int i;

    i = 0;
    while (i < n)
    {
        if (array[i] == x)
        {
            printf("o xarakthras %d vrisketai sth thesh %d", x, i);
            break;
        }
        else
            i = i + 1;
    }
    if (i >= n)
    {
        printf("to stoixeio den vrethike");
    }
}

void Binary_Search(int array[], int size, int key)
{
    int bottom = 0, top = size - 1;
    while (bottom <= top)
    {
        int mid = (top + bottom) / 2;
        if (array[mid] == key)
        {
            printf("To stoixeio %d vrethike sthn thesi %d \n", key, mid);
            return;
        }
        else if (array[mid] > key)
        {
            top = mid - 1;
        }
        else
        {
            bottom = mid + 1;
        }
    }
    printf("O xarakthras %d den vrethike", key);
}

void Interpolation_Search(int array[], int size, int key)
{
    int low = 0, high = size - 1;
    while (array[high] >= key && key > array[low])
    {
        int next = low + ((key - array[low]) / (array[high] - array[low])) * (high - low);
        if (key > array[next])
        {
            low = next + 1;
        }
        else if (key < array[next])
        {
            high = next - 1;
        }
        else
        {
            low = next;
        }

        if (key == array[low])
        {
            printf("To stoixeio %d vrethke sthn thesi %d", key, low);
            return;
        }
    }
    printf("To stoixeio den vrethike !");
}


//========================== BIS ===================================
void search(int array[], int size, int key, int next)
{
    int i;
    printf("%d \n", next);

    for (i = 1; i <= 3; i++)
    {
        if (array[next + i] == key && next >= -3)
        {
            printf("To stoixeio %d vrethike sthn thesi %d", key, next + i);
            return;
        }
    }

    printf("To stoixeio den vrethike !");
}

void Binary_Interpolation_Search(int array[], int n, int key)
{

    int left = 0, right = n - 1, x;
    int size = right - left + 1;
    int next = 1 + ((key - array[left]) / (array[right] - array[left])) * size;
    int sqrtsize = sqrt(size);

    if (array[0] == key)
    {
        printf("To stoixeio %d vrethike sthn thesi %d", key, 0);
        return;
    }

    while (key != array[next])
    {
        int i = 0;
        size = right - left;
        sqrtsize = sqrt(size);
        if (size <= 3)
        {
            search(array, size, key, next);
            return;
        }

        if (key >= array[next])
        {

            while (key > array[next + (i * sqrtsize) - 1])
            {
                i++;
            }
            right = next + i * sqrt(size);
            left = next + (i - 1) * sqrt(size);
        }
        else if (key < array[next])
        {

            while (key < array[next - (i * sqrtsize) + 1])
            {
                i++;
            }
            right = next - (i - 1) * sqrt(size);
            left = next - i * sqrt(size);
        }

        next = left + ((right - left) * (key - array[left]) / (array[right] - array[left])) - 1;
    }
    if (key == array[next])
    {
        printf("To stoixeio %d vrethike sthn thesi %d", key, next);
        return;
    }

    printf("To stoixeio den vrethike !");
}
//===================================================================================================
int main()
{
    int array[10] = {50, 60, 100, 610, 1300, 4000, 7000, 7001, 8000, 10000}, size = 10;
    // linsearch(array, 4, 5);
    //Binary_Search(array, 5, 50);
    //Interpolation_Search(array, size, 1300);
    Binary_Interpolation_Search(array, size, 50);

    return 0;
}