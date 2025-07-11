#include <stdio.h>
#include <stdlib.h>
int top = -1;
int max;
void push(int stack[]);
void pop(int stack[]);
void display(int stack[]);
void main()
{

    printf("Enter the size of the stack: ");
    scanf("%d", &max);
    int *stack = (int *)malloc(max * sizeof(int));
    int choice;
    printf("1.Push \n2.Pop\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4)
        {
            printf("Exiting the program, goodbye!\n");
            free(stack);
            break;
        }
        if (choice < 1 || choice > 4)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        switch (choice)
        {

        case 1:
            push(stack);
            break;

        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
void push(int stack[])
{
    int element;
    if (top == max - 1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        printf("Enter a number to push:");
        scanf("%d", &element);
        top++;
        stack[top] = element;
        printf("Element inserted to the stack!\n");
    }
}
void pop(int stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Element %d removed from the stack!\n", stack[top]);
        top--;
    }
}
void display(int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Elements in the stack are :");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n") l
    }
}