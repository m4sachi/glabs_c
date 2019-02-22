#include "main.h"

static void count_num_of_1()
{
   int number;
   int count = 0, i;
   printf("Enter a number:");
   fflush(stdout);
   scanf("%d", &number);

   for (i = 0; i < sizeof(number) * 8; i++)
   {
      if (number & (1 << i))
      {
         count++;
      }
   }

   printf("The number of 1 in %d = %d\n", number, count);

}

static void clear_bit_pos()
{
   int number;
   int i;
   printf("Enter a number:");
   fflush(stdout);
   scanf("%d", &number);

   printf("Enter the position:");
   fflush(stdout);
   scanf("%d", &i);

   printf("The number before toggle = %x\n", number);

   number = (number & ~(1 << i));

   printf("The number after toggle = %x\n", number);

}
void basic_func()
{
   int choice;

   do
   {
      printf("\n===== Basic C testing =====\n");

      printf("1. Count number of 1's\n");
      printf("2. Clear Bit position\n");
      printf("3. Exit\n");
      printf("Please select:");
      fflush(stdout);

      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         count_num_of_1();
         break;
      case 2:
         clear_bit_pos();
         break;
      case 3:
         printf("Returning to the main function\n");
         return;
      default:
         printf("Invalid Selection\n");
         break;
      }

   } while (choice != 3);

   return;
}
