#include "main.h"

#if 1
typedef struct _NODE
{
   int data;
   struct _NODE *pLeftPtr;
   struct _NODE *pRightPtr;
}NODE, *PNODE;
#endif

void DisplayNode(PNODE pHead)
{
   printf("Node:%p\t Data:%02d\t LeftPtr:%p\t RightPtr:%p\n",
      pHead, pHead->data, pHead->pLeftPtr, pHead->pRightPtr);
}
void DeleteTree(PNODE pHead)
{
   if (pHead == NULL)
      return;

   DeleteTree(pHead->pLeftPtr);
   DeleteTree(pHead->pRightPtr);

   DisplayNode(pHead);

   free(pHead);
}
PNODE AllocNode(data)
{
   PNODE pNode;
   pNode = malloc(sizeof(struct _NODE));
   if (!pNode)
      return NULL;

   pNode->data = data;
   pNode->pLeftPtr = NULL;
   pNode->pRightPtr = NULL;

   return pNode;
}


PNODE AddTreeNode(PNODE *pHead, int data)
{
   PNODE pTraverse = *pHead, pCurrent;
   if (*pHead == NULL)
   {
      *pHead = AllocNode(data);
      return *pHead;
   }
   else if (data < (*pHead)->data)
   {
      (*pHead)->pLeftPtr = AddTreeNode(&(*pHead)->pLeftPtr, data);
   }
   else
   {
      (*pHead)->pRightPtr = AddTreeNode(&(*pHead)->pRightPtr, data);
   }
   return *pHead;

}

void InOrderTraversal(PNODE pHead)
{
   if (pHead == NULL)
      return;

   InOrderTraversal(pHead->pLeftPtr);
   DisplayNode(pHead);
   InOrderTraversal(pHead->pRightPtr);
}
void PrintInOrderTraversal(PNODE pHead)
{
   printf("\nInOrderTraversal:\n");
   InOrderTraversal(pHead);
}

void PreOrderTraversal(PNODE pHead)
{
   if (pHead == NULL)
      return;

   DisplayNode(pHead);
   PreOrderTraversal(pHead->pLeftPtr);
   PreOrderTraversal(pHead->pRightPtr);
}
void PrintPreOrderTraversal(PNODE pHead)
{
   printf("\nPreOrderTraversal:\n");
   PreOrderTraversal(pHead);
}


void PostOrderTraversal(PNODE pHead)
{
   if (pHead == NULL)
      return;

   PostOrderTraversal(pHead->pLeftPtr);
   PostOrderTraversal(pHead->pRightPtr);
   DisplayNode(pHead);
}
void PrintPostOrderTraversal(PNODE pHead)
{
   printf("\nPostOrderTraversal:\n");
   PostOrderTraversal(pHead);
}

int HeightTree(PNODE pHead)
{
   int lh =0, rh=0;
   if (pHead == NULL)
      return 0;
   if (pHead->pLeftPtr)
      lh = HeightTree(pHead->pLeftPtr);
   if (pHead->pRightPtr)
      rh = HeightTree(pHead->pRightPtr);

   return (MAX(lh, rh) + 1);
}
void PrintHeightTree(PNODE pHead)
{
   int height = 0;

   height = HeightTree(pHead);

   printf("\nHeight of Tree:%d", height);
}

int LengthTree(PNODE pHead)
{
   if (pHead == NULL)
      return 0;
   else
   {
      return (LengthTree(pHead->pLeftPtr) + LengthTree(pHead->pRightPtr) + 1);
   }
}

void FindLengthTree(PNODE pHead)
{
   int Length = 0;
   Length = LengthTree(pHead);

   printf("\nElements of Tree:%d", Length);
}


int MinTree(PNODE pHead)
{
   if (pHead == NULL)
      return 0;
   while (pHead->pLeftPtr != NULL)
   {
      pHead = pHead->pLeftPtr;
   }
   return pHead->data;
}

void FindMinTree(PNODE pHead)
{
   int Min = 0;

   Min = MinTree(pHead);

   printf("\nMinimum value in Tree:%d", Min);
}

void CreateTree(PNODE *pHead)
{
   int i;
   int TreeNodes;

   DeleteTree(*pHead);

   *pHead = NULL;

   //printf("Enter Node Value:");
   //fflush(stdout);
   //scanf("%d", &data);


   TreeNodes = rand();

   TreeNodes = TreeNodes % 30;
   if (TreeNodes < 10)
      TreeNodes = 11;

   // Create a new list
   for (i = 0; i < TreeNodes; i++)
   {
      AddTreeNode(pHead, rand()%100);
   }


   PrintAsciiTree(*pHead);
#if 0   
   printf("\n");
   PrintInOrderTraversal(*pHead);
   PrintPreOrderTraversal(*pHead);
   PrintPostOrderTraversal(*pHead);
   PrintHeightTree(*pHead);
#endif
#if 0
   AddTreeNode(pHead, 60);

   //Dummy write
   AddTreeNode(pHead, 50);
   AddTreeNode(pHead, 40);
   AddTreeNode(pHead, 65);
   AddTreeNode(pHead, 20);
   AddTreeNode(pHead, 45);
   AddTreeNode(pHead, 30);
#endif
}

void AddNode(PNODE pHead)
{
   int Data;
   printf("Add a Node Value:");
   fflush(stdout);
   scanf("%d", &Data);

   AddTreeNode(&pHead, Data);

   PrintAsciiTree(pHead);
}


void Tree()
{
   int choice;

   PNODE pHead = NULL;

   do
   {
      printf("\n===== Tree DataStructure testing =====\n");

      printf("1. Create Tree\n");
      printf("2. InOrder Display\n");
      printf("3. PreOrder Display\n");
      printf("4. PostOrder Tree\n");
      printf("5: Height of Tree\n");
      printf("6: Number of Elements in a Tree\n");
      printf("7: Minimum value in a Tree\n");
      printf("8: Insert a Node\n\n");

      printf("11: AVL tree Add\n");
      printf("99: Display Tree\n");
      printf("100: Exit\n");
      printf("Please select:");
      fflush(stdout);
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         CreateTree(&pHead);
         break;
      case 2:
         InOrderTraversal(pHead);
         break;
      case 3:
         PreOrderTraversal(pHead);
         break;
      case 4:
         PostOrderTraversal(pHead);
         break;
      case 5:
         PrintHeightTree(pHead);
         break;
      case 6:
         FindLengthTree(pHead);
         break;
      case 7:
         FindMinTree(pHead);
         break;
      case 8:
         AddNode(pHead);
         break;
      case 11:
         AVLTreeImplementaion();
         break;
      case 99:
         PrintAsciiTree(pHead);
         break;
      case 100:
         break;
      default:
         printf("Invalid Selection\n");
         break;
      }

   } while (choice != 100);
}