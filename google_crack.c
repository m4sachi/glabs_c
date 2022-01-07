#include "main.h"

int find_sum_of_two(int *array, int length, int sum)
{
    int Parsenumbers[20] = {0};
    int diff;
    int i;

    for(int i=0; i<length; i++)
    {
        diff = sum - *(array+i);
        if(diff < 0)
            continue;
        if(Parsenumbers[diff])
        {
            for(i=0;i<20;i++)
            {
                printf("%d\t", Parsenumbers[i]);
            }
            printf("\n");
            return diff;
        }
        else
            Parsenumbers[*(array+i)] = 1;
    }

    return 0;
}
void array_counting()
{
    int array[] = {1, 9, 2, 19, 14, 8};
    int i;
    int sum = 17;
    int length = sizeof(array)/sizeof(int);
    int diff;

    printf("array is:\n");
    for(i=0; i<sizeof(array)/sizeof(int); i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    diff = find_sum_of_two(array, length, sum);
    if(diff)
    {
        printf("Found the two numbers: %d %d\n", diff, sum-diff);
    }

}
void GoogleCrack()
{
    int choice;
    do
    {
        printf("\n===== Coding Qns asked for Google =====\n");

        printf("1. Sum of two elements in an array\n");
        printf("50. Exit\n");
        printf("Please select:");
        fflush(stdout);

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            array_counting();
            break;
        case 3:
            printf("Returning to the main function\n");
            return;
        default:
            printf("Invalid Selection\n");
            break;
        }

    } while (choice != 50);
}