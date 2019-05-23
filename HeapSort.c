#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void heapsort(int array[], int size)
{
    int l = size / 2+1;
    int r = size-1;
    int j, k;
    printf("%d\n",l);

    while (r >= 1)
    {
        if (l > 0)
        {
            l--;
            j = l;
        }
        else
        {
            swap(&array[0], &array[r]);
            r--;
            j = 0;
        }
        int s = array[j];
        while (2 * j <= r)
        {
            k = 2 * j;
            if (k < r && array[k] < array[k + 1])
            {
                k++;
            }
            if (s < array[k])
            {
                swap(&array[j],&array[k]);
                j = k;
            }
            else
            {
                
                break;
            }
        }
    }
}
void print(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d  ", array[i]);
    printf("\n");
}

int main()
{

    //=============================================
    // dhmiourgia pinaka kai tou antigrafou
    int array[40], size =40 ;
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = rand() % 20 + 1;
    }
    int temp[40];
    print(array, size);
    memcpy(temp, array, sizeof(array));

    heapsort(temp, size);
    print(temp, size);
    //=============================================
    double time;
    clock_t start, end;
}