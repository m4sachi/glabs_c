#include "main.h"

static int g_array[1000];
static int g_size;


void PrintArray()
{
    int i=0;

    printf("\n");
    for(i=0;i<g_size;i++)
    {
        printf("%d  ", g_array[i]);
    }
    printf("\n");

}

int *input(int *size)
{
    int i=0;

    printf("Enter the array size:");
    fflush(stdout);

    scanf("%d", size);

    for(i=0; i<*size; i++)
    {
        scanf("%d", &g_array[i]);
    }

    g_size = *size;

    return g_array;

}


void Merge(int array[], int l, int m, int r)
{
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;

   int L[20], R[20];

   for (i = 0; i < n1; i++)
   {
      L[i] = array[l + i];
   }

   for (j = 0; j < n2; j++)
   {
      L[j] = array[m+1+j];
   }
}

void MergeSorting(int array[], int l, int r)
{
   if (l < r)
   {
      int m = (l + r) / 2;
      MergeSorting(array, l, m);
      MergeSorting(array, m+1, r);

      Merge(array, l, m, r);
   }
}
void MergeSort()
{
   int *array, size;
   int pos, i, temp;

   array = input(&size);

   PrintArray();

   // Algorithm Recursive logic
   MergeSorting(array, 0, size - 1);
}

void InsertionSort()
{
    int *array, size;
    int pos, i, temp;

    array = input(&size);

    PrintArray();

    // Algorithm
    for(pos=1; pos<size; pos++)
    {
        temp = array[pos];

        i = pos - 1;
        while (i >= 0 && array[i] > temp)
        {
           array[i + 1] = array[i];
           pos = pos - 1;
        }

        array[i+1] = temp;
    }

    printf("Sorted Array \n");
    PrintArray();

}

void Selection_Sort()
{
    int i, j, min_index;
    int temp;
    int *array, size;


    array = input(&size);

    PrintArray();

    // Sorting Started
    for(i=0;i<size-1;i++)
    {
        min_index = i;
        for(j=i+1; j<size; j++)
        {
            if(array[j] < array[min_index])
            {
                min_index = j;
            }
        }

        // swap the variable
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }

    PrintArray();

}

void BubbleSort()
{
    int *array;
    int size;

    int i,j;
    int temp;
    array =input(&size);

    PrintArray();

    // Algorithm
    for(i=0;i<size; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    PrintArray();

}
void sort_func()
{
   int choice;

   do
   {
      printf("\n\n");
      printf("Array implementation:\n");
      printf("1: Selection Sort\n");
      printf("2: Bubble Sort\n");
      printf("3: Insertion Sort\n");
      printf("4: Merge Sort\n");
      printf("9: Exit\n");
      printf("Select the sort method:");
      fflush(stdout);
      scanf("%d", &choice);

      switch(choice)
      {
         case 1:
            Selection_Sort();
            break;
         case 2:
            BubbleSort();
            break;
         case 3:
            InsertionSort();
            break;
         case 4:
            MergeSort();
            break;
         default:
            break;
      }
   }while(choice!=9);
}
