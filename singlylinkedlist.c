#include "main.h"

typedef struct _Node
{
   int data;
   struct _Node *ptr;
}NODE, *PNODE;

void Display_SList(PNODE pHead)
{
   printf("\n\nLinked list\n");
   PNODE pTemp = pHead;
   while (pTemp)
   {
      printf("Node Address: %p\t Value:%d\t NextPtr:%p\n", pTemp, pTemp->data, pTemp->ptr);
      pTemp = pTemp->ptr;
   }
}

void Create_SNode_Head(PNODE *pHead)
{
   PNODE pNode;

   pNode = malloc(sizeof(NODE));
   if (pNode)
   {
      pNode->data = 0;
      pNode->ptr = NULL;
   }

   printf("Enter the Node Value:");
   fflush(stdout);
   scanf("%d", &pNode->data);

   if (*pHead == NULL)
   {
      *pHead = pNode;
   }
   else
   {
      pNode->ptr = *pHead;
      *pHead = pNode;
   }

}


void Create_SNode_Tail(PNODE *pHead)
{
   PNODE pNode;

   pNode = malloc(sizeof(NODE));
   if (pNode)
   {
      pNode->data = 0;
      pNode->ptr = NULL;
   }

   printf("Enter the Node Value:");
   fflush(stdout);
   scanf("%d", &pNode->data);

   if (*pHead == NULL)
   {
      *pHead = pNode;
   }
   else
   {
      PNODE pTemp = *pHead;
      while (pTemp->ptr)
      {
         pTemp = pTemp->ptr;
      }
      pTemp->ptr = pNode;
   }
}


void Delete_SNode_Head(PNODE *pHead)
{

   PNODE pTemp;

   pTemp = *pHead;
   if (pTemp == NULL)
   {
      printf("List is empty\n");
      return;
   }
   *pHead = (*pHead)->ptr;

   printf("Deleted Node Details\n");
   printf("Node Address: %p\t Value:%d\t NextPtr:%p\n", pTemp, pTemp->data, pTemp->ptr);

   free(pTemp);
}


void Delete_SNode_Tail(PNODE *pHead)
{
   PNODE pTemp = *pHead;

   if (pTemp == NULL)
   {
      printf("List Empty\n");
   }
   else if (pTemp->ptr == NULL)
   {
      printf("Node Address: %p\t Value:%d\t NextPtr:%p\n", pTemp, pTemp->data, pTemp->ptr);
      free(pTemp);
      *pHead = NULL;
   }
   else
   {
      PNODE pNext = pTemp->ptr;
      while (pNext->ptr != NULL)
      {
         pTemp = pNext;
         pNext = pNext->ptr;
      }

      printf("Node Address: %p\t Value:%d\t NextPtr:%p\n", pNext, pNext->data, pNext->ptr);
      free(pNext);
      pTemp->ptr = NULL;
   }
}


void Delete_SNode_Index(PNODE *pHead)
{
   int index, i=0;
   PNODE pPrev = *pHead, pNext;
   printf("Enter the Index(Starting from 0) to be deleted:");
   fflush(stdout);
   scanf("%d", &index);

   if (*pHead == NULL)
   {
      printf("List Empty\n");
   }
   else if (pPrev && index == 0)
   {
      *pHead = (*pHead)->ptr;
      printf("Node Address: %p\t Value:%d\t NextPtr:%p\n", pPrev, pPrev->data, pPrev->ptr);
      free(pPrev);
   }
   else
   {
      i = 1;
      pNext = pPrev->ptr;
      while (pNext)
      {
         if (i == index)
         {
            pPrev->ptr = pNext->ptr;
            printf("Node Address: %p\t Value:%d\t NextPtr:%p\n", pNext, pNext->data, pNext->ptr);
            free(pNext);
            break;
         }
         pPrev = pNext;
         pNext = pNext->ptr;
         i++;
      }
   }

}


void Reverse_SList(PNODE *pHead)
{
   PNODE pPrev, pCurr, pNext;

   pPrev = NULL;
   pCurr = *pHead;
   pNext = NULL;

   while (pCurr)
   {
      pNext = pCurr->ptr;
      pCurr->ptr = pPrev;
      pPrev = pCurr;
      pCurr = pNext;
   }

   *pHead = pPrev;

   printf("Linked list is reversed:\n");
   Display_SList(*pHead);
}

PNODE reverse(PNODE pHead)
{
   PNODE pRevHead;
   if (pHead == NULL || pHead->ptr == NULL)
      return pHead;
   pRevHead = reverse(pHead->ptr);

   pHead->ptr->ptr = pHead;
   pHead->ptr = NULL;

   return pRevHead;


}
void Rec_Reverse_SList(PNODE *pHead)
{
   *pHead = reverse(*pHead);

   Display_SList(*pHead);
}


void Sort_SList(PNODE *pHead)
{
   PNODE pStart = *pHead;
   PNODE pMin, pTraverse;
   int temp;

   while (pStart->ptr)
   {
      pMin = pStart;
      pTraverse = pStart->ptr;
      while (pTraverse)
      {
         if (pTraverse->data < pMin->data)
         {
            pMin = pTraverse;
         }
         pTraverse = pTraverse->ptr;
      }

      temp = pMin->data;
      pMin->data = pStart->data;
      pStart->data = temp;

      pStart = pStart->ptr;
   }
}


void FindMiddle_SList(PNODE *pHead)
{
   PNODE pSlowNode = *pHead;
   PNODE pFastNode = *pHead;

   while (pSlowNode && pFastNode && pFastNode->ptr)
   {
      pSlowNode = pSlowNode->ptr;
      pFastNode = pFastNode->ptr->ptr;
   }

   printf("The middle Node:%p\t Data:%d\t Ptr:%p\n", 
      pSlowNode, pSlowNode->data, pSlowNode->ptr);
}

void RandomAdd(PNODE *pHead, int value)
{
   PNODE pNode;

   pNode = malloc(sizeof(NODE));
   if (!pNode)
   {
      return;
   }
 
   pNode->data = value;
   pNode->ptr = NULL;

   if (*pHead == NULL)
   {
      *pHead = pNode;
   }
   else
   {
      pNode->ptr = *pHead;
      *pHead = pNode;
   }
}

void CountNode_Slist(PNODE *pHead)
{
   int count = 0;
   PNODE pTraverse = *pHead;

   while (pTraverse)
   {
      count++;
      pTraverse = pTraverse->ptr;
   }

   printf("\nThere are %d Nodes Present\n", count);
}

void FindNthNodeFromLast_Slist(PNODE *pHead)
{
   int value;
   PNODE pFastNode = *pHead;
   PNODE pSlowNode = *pHead;

   printf("Node Location from Last:");
   fflush(stdout);
   scanf("%d", &value);

   while (pFastNode && value--)
   {
      pFastNode = pFastNode->ptr;
   }
   if (pFastNode == NULL)
      return;
   while (pFastNode)
   {
      pSlowNode = pSlowNode->ptr;
      pFastNode = pFastNode->ptr;
   }

   printf("The Node:%p\t %d\t %p", pSlowNode, pSlowNode->data, pSlowNode->ptr);
}

void DetectLoop(PNODE *pHead)
{
   PNODE pSlowPtr = *pHead;
   PNODE pFastPtr = *pHead;
   PNODE pTemp;
   int LoopDetected=0;
   int position=0; 

   printf("Loop detection started\n");

   while(pSlowPtr && pFastPtr && pFastPtr->ptr)
   {
      pSlowPtr = pSlowPtr->ptr;
      pFastPtr = pFastPtr->ptr->ptr;

      if(pSlowPtr == pFastPtr)
      {
         LoopDetected = 1;
         break;
      }
   }

   if(LoopDetected)
   {
      pFastPtr = *pHead;
      while(pSlowPtr != pFastPtr)
      {
         pTemp = pSlowPtr;
         pSlowPtr= pSlowPtr->ptr;
         pFastPtr= pFastPtr->ptr;
         position++;
      }
      printf("Loop Detected at position:%d\n", position);
      printf("Node Address: %p\t Value:%d\t NextPtr:%p\n", pSlowPtr, pSlowPtr->data, pSlowPtr->ptr);

      pTemp->ptr = NULL;

      Display_SList(*pHead);
   }
   else
      printf("No loop detected");


}
void Random_List(PNODE *pHead)
{
   int i;
   int ListLength;

   // Delete the older list
   while (*pHead)
   {
      Delete_SNode_Tail(pHead);
   }

   ListLength = rand();

   ListLength = ListLength % 30;
   if (ListLength < 10)
      ListLength = 11;

   // Create a new list
   for (i = 0; i < ListLength; i++)
   {
      RandomAdd(pHead, rand()%100);
   }

   Display_SList(*pHead);
}

void Loop_List(PNODE *pHead)
{
   int i;
   int ListLength;
   int LoopConnect;
   PNODE pTemp1;
   PNODE pTemp2;

   // Delete the older list
   while (*pHead)
   {
      Delete_SNode_Tail(pHead);
   }

   ListLength = rand();

   ListLength = ListLength % 30;
   if (ListLength < 10)
      ListLength = 11;

   // Create a new list
   for (i = 0; i < ListLength; i++)
   {
      RandomAdd(pHead, rand()%100);
   }

   pTemp1 = pTemp2 = *pHead;
   LoopConnect = rand();
   LoopConnect = LoopConnect % 30;
   LoopConnect++;

   Display_SList(*pHead);
   printf("\nInject the loop at position %d\n", LoopConnect);

   for(i=0;i<LoopConnect;i++)
      pTemp1= pTemp1->ptr;
   while(pTemp2->ptr != NULL)
      pTemp2 = pTemp2->ptr;

   pTemp2->ptr = pTemp1;

}

void Single_Linkedlist()
{
   int choice;

   // Head Pointter
   PNODE pHead = NULL;

   do
   {
      printf("\n\n");
      printf("Singly Linked List implementation:\n");
      printf("1: Create the Node at Head\n");
      printf("2: Create the Node at Tail\n");
      printf("3: Delete Node at Head\n");
      printf("4: Delete Node at Tail\n");
      printf("5: Delete Node with Index\n");
      printf("6: Reverse the Singly linkedlist\n");
      printf("7: Recursive Reverse the Singly linkedlist\n");
      printf("8: Sorting the Singly Linkedlist\n");
      printf("9: Finding Middle of Linkedlist\n");
      printf("10: Count the Nodes in Linkedlist\n");
      printf("11: Find the nth Node from Last of linkedlist\n");
      printf("12: Detect the Loop and start of Loop\n");

      printf("77: Random List creator\n");
      printf("88: Random List creator with Loop\n");
      printf("99: Displays Nodes\n");
      printf("100: Exit\n");
      printf("Please Select: ");
      fflush(stdout);
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         Create_SNode_Head(&pHead);
         break;
      case 2:
         Create_SNode_Tail(&pHead);
         break;
      case 3:
         Delete_SNode_Head(&pHead);
         break;
      case 4:
         Delete_SNode_Tail(&pHead);
         break;
      case 5:
         Delete_SNode_Index(&pHead);
         break;
      case 6:
         Reverse_SList(&pHead);
         break;
      case 7:
         Rec_Reverse_SList(&pHead);
         break;
      case 8:
         Sort_SList(&pHead);
         break;
      case 9:
         FindMiddle_SList(&pHead);
         break;
      case 10:
         CountNode_Slist(&pHead);
         break;
      case 11:
         FindNthNodeFromLast_Slist(&pHead);
         break;
      case 12:
         DetectLoop(&pHead);
         break;
      case 77:
         Random_List(&pHead);
         break;
      case 88:
         Loop_List(&pHead);
         break;
      case 99:
         Display_SList(pHead);
         break;
      default:
         break;
      }
   } while (choice != 100);
}