#include <stdio.h>
#include <stdlib.h>
int top = -1, max;
void push(int stack[]);
void pop(int stack[]);
void display(int stack[]);
int isFull();
int isEmpty();
void peek(int stack[]);
int main()
{

    printf("Enter the size of the stack: ");
    scanf("%d", &max);
    int *stack = (int *)malloc(max * sizeof(int));
    int choice;
    printf("1.Push \n2.Pop\n3.Display\n4.Is Full?\n5.Is Empty?\n6.peek\n7.Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
        case 4:
            printf(isFull() ? "Stack is Full!\n" : "Stack is not full!\n");
            break;
        case 5:
            printf(isEmpty() ? "Stack is Empty!\n" : "Stack is not empty!\n");
            break;
        case 6:
            peek(stack);
            break;
        case 7:
            free(stack);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void push(int stack[])
{
    int element;
    if (isFull())
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter a number to push: ");
        scanf("%d", &element);
        top++;
        stack[top] = element;
        printf("Element inserted to the stack!\n");
    }
}
void pop(int stack[])
{
    if (isEmpty())
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
        printf("\n");
    }
}
int isEmpty()
{
    
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isFull()
{
    
    if (top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void peek(int stack[])
{
    if (isEmpty())
    {
        printf("Stack is empty. Nothing to peek!\n");
    }
    else
    {
        printf("Top of the stack :%d\n", stack[top]);
    }
}