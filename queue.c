#include<stdio.h>
#include<stdlib.h>
int front =-1, rear=-1, max;
void enqueue(int queue[]);
void dequeue(int queue[]);
void display(int queue[]);
int isFull();
int isEmpty();
void peek(int queue[]);
int main()
{

    printf("Enter the size of the queue: ");
    scanf("%d", &max);
    int *queue = (int *)malloc(max * sizeof(int));
    int choice;
    
    while (1)
    {
        printf("\n1. Enqueue \n2. Dequeue\n3. Display\n4. Is Full?\n5. Is Empty?\n6. Peek\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {

        case 1:
            enqueue(queue);
            break;

        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            printf(isFull()?"Queue is Full!\n":"Queue is not full\n");
            break;
        case 5:
            printf(isEmpty()?"Queue is empty!\n":"Queue is not empty\n");
            break;
        case 6:
            peek(queue);
            break;
        case 7:
            printf("Exiting the program, goodbye!\n");
            free(queue);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void enqueue(int queue[]){
    if(isFull()){
        printf("Queue Overflow!\n");
        return;
    }
        int element;
        printf("Enter a number to enqueue: ");
        scanf("%d", &element);
        if(front==-1){
            front = 0;
            rear = 0;
        }else{
            rear++;
        }
            queue[rear] = element;
            printf("Element %d inserted to the queue!\n", queue[rear]);

    }

void dequeue(int queue[]){
    if(isEmpty()){
        printf("Queue Underflow!\n");
    }else{
        printf("Element %d removed from the queue!\n", queue[front]);
        front++;
        if(front > rear){
            front = -1;
            rear = -1;  
        }
    }
}
void display(int queue[])
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Elements in the queue are :");
        for (int i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int isFull()
{
    return (rear == max - 1);
}

int isEmpty()
{
    return (rear == -1);
}
void peek(int queue[]){
    if(isEmpty()){
        printf("Queue is empty. nothing to peek!");
    }
    else{
        printf("Front element: %d Rear element: %d",queue[front],queue[rear]);
    }
}
