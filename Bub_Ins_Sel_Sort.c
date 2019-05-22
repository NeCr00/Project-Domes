#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
void Bubble_Sort(int array[], int size)
{
   int i, j;

   for (i = 0; i < size - 1; i++)
   {
      for (j = 0; j < size - 1; j++)
      {
         if (array[j] > array[j + 1])
         {
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
         }
      }
   }
}

void Insertion_Sort(int array[], int size)
{
   int i, j;

   for (i = 1; i < size; i++)
   {
      int x = array[i];
      int j = i - 1;
      while (j >= 0 && x < array[j])
      {
         array[j + 1] = array[j];
         j--;
      }
      array[j + 1] = x;
   }
}

void Selection_Sort(int array[], int size)
{
   int i, j,min;

   for (i = 0; i < size - 1; i++)
   {     min = i;
      for (j =i+1; j < size; j++)
      {
         if (array[min] > array[j])
         {
           min = j ;
         }
      }
            int temp =array[min];
            array[min] = array[i]; 
            array[i] = temp;
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
   int array[5000], size = 5000;
   int i;
   for (i = 0; i < size; i++)
   {
      array[i] = rand() % 1000 + 1;
   }
   int temp[5000];
   memcpy(temp, array, sizeof(array));
   //=============================================
   double time;
   clock_t start, end;

   //=============Bubble Sort=========================
   start = clock();
   Bubble_Sort(temp, size);
   end = clock();
   time = ((double)(end - start)) / CLK_TCK;
   printf("Total time of Bubble Sort execution is %lf\n", time);

   memcpy(temp, array, sizeof(array));
  
   //=============Insertion Sort======================
   start = clock();
   Insertion_Sort(temp, size);
   end = clock();
   time = ((double)(end - start)) / CLK_TCK;
   printf("Total time of Insertion Sort execution is %lf\n", time);

   memcpy(temp, array, sizeof(array));
   
   //=============Selection Sort======================
   start = clock();
   Selection_Sort(temp, size);
   end = clock();
   time = ((double)(end - start)) / CLK_TCK;
   printf("Total time of Insertion Sort execution is %lf\n", time);

   return 0;
}
