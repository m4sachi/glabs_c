#include "main.h"

#define DBG
#define MAX_CHAR 1000

int is_palindrome(char *str, int i, int j)
{
   while(i!=j)
   {
      if(*(str+i) != *(str+j))
      {
         return 0;
      }
      i++;
      j--;
   }
   return 1;
}

void LargestPalindrome()
{
   char string[]="lol malayalam is palndirome";
   char ch;
   int i,j;
   int length=0;
   struct _largest_data{
      char *str;
      int str_len;
   }largest_data = {NULL,0};

#if 0
   printf("Enter the string:");
   fflush(stdout);
   for(i=0; (ch=getchar())!=EOF && ch!= '\n'; i++)
      string[i] = ch;
   if(ch == '\n')
   {
      printf("Tet........\n");
      string[i] = '\0';
   }
#endif

   length = strlen(string);
#ifdef DBG
   printf("Length:%d\n", length);
#endif
   for(i=0; i<length; i++)
   {
      for(j=i;j<length;j++)
      {
         if(is_palindrome(string, i, j))
         {
#ifdef DBG
            printf("palindrome detected\t i:%d j:%d\n", i, j);
#endif
            if(largest_data.str_len < j-i)
            {
               largest_data.str = (string+i);
               largest_data.str_len = j-i+1;
            }
         }
      }
   }

   printf("Largest palindome:\t string_length:%d\n", largest_data.str_len);
   for(i=0;i<largest_data.str_len;i++)
      printf("%c", *(largest_data.str +i));
   printf("\n");
}


void string_func()
{
   int choice;
   printf("This Sub routine is used to add all the String manipulations\n");

   printf("1: Largest Palindrome\n");

   printf("Select choice:");
   scanf("%d", &choice);
   switch(choice)
   {
      case 1:
         LargestPalindrome();
         break;
      default:
         printf("Invalid Selection. Returning\n");
         return;
   }
   return;
}
