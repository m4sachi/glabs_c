#include "main.h"

typedef struct _AvlNode
{
    int Data;
    int Height;
    struct _AvlNode *pLeftPtr;
    struct _AvlNode *pRightPtr;
}AVLNODE, *PAVLNODE;

//Declaration to avoid code compialtion issues
typedef struct _NODE
{
   int data;
   struct _NODE *pLeftPtr;
   struct _NODE *pRightPtr;
}NODE, *PNODE;


PAVLNODE pAvlHead=NULL;

/* Get the AvlNodeHeight */
static int AVlNodeHeight(PAVLNODE pAvlNode)
{
    int hl, hr;
    
    hl = pAvlNode && pAvlNode->pLeftPtr?pAvlNode->pLeftPtr->Height:0;
    hr = pAvlNode && pAvlNode->pRightPtr?pAvlNode->pRightPtr->Height:0;

    return hl>hr?hl+1:hr+1;
}

/* Get the balance Factor */
static int BalanceFactor(PAVLNODE pAvlNode)
{
    int hl, hr;
    
    hl = pAvlNode && pAvlNode->pLeftPtr?pAvlNode->pLeftPtr->Height:0;
    hr = pAvlNode && pAvlNode->pRightPtr?pAvlNode->pRightPtr->Height:0;

    return hl-hr;
}

/*
 LL Rotation: if BF is 2 and the Child BF =1
*/
PAVLNODE LLRotation(PAVLNODE pNode)
{
    PAVLNODE pLeft = pNode->pLeftPtr;
    PAVLNODE pLeftRight = pLeft->pRightPtr;

    pLeft->pRightPtr = pNode;
    pNode->pLeftPtr = pLeftRight;

    pNode->Height = AVlNodeHeight(pNode);
    pLeft->Height = AVlNodeHeight(pLeft);

    if(pAvlHead == pNode)
        pAvlHead = pLeft;

    return pLeft;
}

/*
 LR Rotation: if BF is 2 and the Child BF =-1
*/
PAVLNODE LRRotation(PAVLNODE pNode)
{
    PAVLNODE pLeft = pNode->pLeftPtr;
    PAVLNODE pLeftRight = pLeft->pRightPtr;

    pNode->pLeftPtr = pLeftRight->pRightPtr;
    pLeft->pRightPtr = pLeftRight->pLeftPtr;

    pLeftRight->pRightPtr= pNode;
    pLeftRight->pLeftPtr = pLeft;

    pLeft->Height = AVlNodeHeight(pLeft);
    pNode->Height = AVlNodeHeight(pNode);
    pLeftRight->Height = AVlNodeHeight(pLeftRight);

    if(pAvlHead == pNode)
        pAvlHead = pLeftRight;

    return pLeftRight;
}

/*
 RL Rotation: if BF is -2 and the Child BF = 1
*/
PAVLNODE RLRotation(PAVLNODE pNode)
{
    PAVLNODE pRight = pNode->pRightPtr;
    PAVLNODE pRightLeft = pRight->pLeftPtr;

    pNode->pRightPtr = pRightLeft->pLeftPtr;
    pRight->pLeftPtr = pRightLeft->pRightPtr;

    pRightLeft->pLeftPtr= pNode;
    pRightLeft->pRightPtr = pRight;

    pRight->Height = AVlNodeHeight(pRight);
    pNode->Height = AVlNodeHeight(pNode);
    pRightLeft->Height = AVlNodeHeight(pRightLeft);

    if(pAvlHead == pNode)
        pAvlHead = pRightLeft;
    return pRightLeft;
}

/*
 RR Rotation: if BF is -2 and the Child BF = -1
*/
PAVLNODE RRRotation(PAVLNODE pNode)
{
    PAVLNODE pRight = pNode->pRightPtr;
    PAVLNODE pRightLeft = pRight->pLeftPtr;

    pRight->pLeftPtr = pNode;
    pNode->pRightPtr = pRightLeft;

    pNode->Height = AVlNodeHeight(pNode);
    pRight->Height = AVlNodeHeight(pRight);

    if(pAvlHead == pNode)
        pAvlHead = pRight;
    return pRight;
}



PAVLNODE InsertAVLTree(PAVLNODE pNode, int Data)
{
    int lbf, rbf;
    PAVLNODE Temp = NULL;

    if(pNode == NULL)
    {
        Temp = malloc(sizeof(AVLNODE));
        if(Temp == NULL)
        {
            printf("Allocation failed\n");
            return NULL;
        }
        else
        {
            Temp->Data = Data;
            Temp->Height = 1;
            Temp->pLeftPtr = Temp->pRightPtr = NULL;
            return Temp;
        }
    }
    if(Data < pNode->Data)
    {
        pNode->pLeftPtr = InsertAVLTree(pNode->pLeftPtr, Data);
    }
    else
    {
        pNode->pRightPtr = InsertAVLTree(pNode->pRightPtr, Data);
    }

    pNode->Height = AVlNodeHeight(pNode);

    if(BalanceFactor(pNode) == 2 && BalanceFactor((pNode)->pLeftPtr) == 1)
        return LLRotation(pNode);
    else if(BalanceFactor(pNode) == 2 && BalanceFactor((pNode)->pLeftPtr) == -1)
        return LRRotation(pNode);
    else if(BalanceFactor(pNode) == -2 && BalanceFactor((pNode)->pRightPtr) == -1)
        return RRRotation(pNode);
    else if(BalanceFactor(pNode) == -2 && BalanceFactor((pNode)->pRightPtr) == 1)
        return RLRotation(pNode);
    
    return (pNode);
}



void AVLTree()
{
   int Data;
   printf("\nTree nodes Value(Value 1000 to exit):");
   fflush(stdout);
   scanf("%d", &Data);

   do
   {
      if(Data == 1000)
         break;
        if(pAvlHead == NULL)
            pAvlHead = InsertAVLTree(pAvlHead, Data);
        else
            InsertAVLTree(pAvlHead, Data);
        
        // Print in pictorial form of tree.
        PrintAsciiTree((PNODE)pAvlHead);
        
        printf("\nTree nodes Value(Value 1000 to exit):");
        fflush(stdout);
        scanf("%d", &Data);
   } while (1);   
}

/* Initial function to implement other AVLTree operations */
void AVLTreeImplementaion()
{
    int choice;

    do
    {
        printf("\n===== AVL Tree DataStructure testing =====\n");

        printf("1. Add AVL Node\n");
        printf("2. Display Tree\n");
        printf("100: Exit\n");
        printf("Please select:");
        fflush(stdout);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AVLTree();
            PrintAsciiTree((PNODE)pAvlHead);
            break;
        case 2:
            PrintAsciiTree((PNODE)pAvlHead);
            break;
        case 100:
            break;
        default:
            printf("Invalid Selection\n");
            break;
        }

    } while (choice != 100);

}
