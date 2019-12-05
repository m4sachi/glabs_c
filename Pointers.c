#include "main.h"

struct _inner_struct
{
   int e;
};

typedef struct _sample_struct
{
   int a;
   int b;
   struct _inner_struct c;
   char d;
}SAMPLE, *pSAMPLE;

#define container_of(ptr, type, member) ({      \
         const typeof( ((type *)0)->member) *__mptr = (ptr);    \
         (type *)( (char *)__mptr - offsetof(type, member) ); })

void Pointers()
{


   SAMPLE SampleTest;

   struct _inner_struct *ptr = &SampleTest.c;
   struct _sample_struct *ptr1;

   //ptr11 = containerof(ptr, struct _sample_struct, c)
}