#include "main.h"

/* General Routine For Executing all the functions */
void main()
{
   int choice = 4;
   fflush(stdin);
   do {

      printf("1. Basic\n");
      printf("2. Array\n");
      printf("3. Strings\n");
      printf("4. Sort\n");
      printf("5. SinglyLinkedList\n");
      printf("6. Pointers\n");
      printf("7. Tree\n");
      printf("8. Google Interview questions\n");
      printf("9. Exit\n");
      printf("Select the Section:");
      // Used for linux bash compiling
      fflush(stdout);

      scanf("%d", &choice);

      switch(choice)
      {
         case 1:
            basic_func();
            break;
         case 2:
            array_func();
            break;
         case 3:
            string_func();
            break;
         case 4:
            sort_func();
            break;
         case 5:
            Single_Linkedlist();
            break;
         case 6:
            Pointers();
            break;
         case 7:
            Tree();
            break;
         case 8:
            GoogleCrack();
            break;
         case 9:
            printf("Exiting the Program\n");
            exit(0);
         default:
            printf("Invalid Selection\n");

      }
   }while(choice != 9);

   printf("Exiting the Program...");

   return ;
}
