#include "main.h"

void two_dimensional_array()
{
#include<stdio.h>

   int a[4][5] = { 0 };
   int i, j;
   int counter = 0;

   for (i = 0; i < 4; i++)
   {
      for (j = 0; j < 5; j++)
      {
         a[i][j] = counter++;
         printf("a[%d][%d]=%d\t", i, j, a[i][j]);
      }
      printf("\n");
   }

   printf("\nPointer Arithmetic\n");
   for (i = 0; i < 4; i++)
   {
      printf("a[%d] = %p\n", i, a[i]);
   }

   int *ptr;

   ptr = a[0];
   printf("ptr = %p\n", ptr);
   ptr = ptr + 1;
   printf("ptr + 1 = %p\n", ptr);

   int **dptr = a;

   printf("*dptr = %p\n", *dptr);
   *dptr = *dptr + 1;
   printf("*dptr + 1 = %p", *dptr);


}
void array_func()
{
   int choice;
   do
   {

      printf("\n===== Basic Array testing =====\n");

      printf("1. Find Smallest number in array\n");
      printf("2. Size of Array\n");
      printf("3: Two dimensional array\n");
      printf("100. Exit\n");
      printf("Please select:");
      fflush(stdout);

      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         //TODO
         break;
      case 2:
         //TODO;
         break;
      case 3:
         two_dimensional_array();
         break;
      default:
         break;
      }
   }while (choice != 100);
   return;

}
