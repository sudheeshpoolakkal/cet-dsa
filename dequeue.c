#include<stdio.h>
#include<stdlib.h>
int front =-1, rear=-1, max;
void insertFront(int dequeue[]);
void insertRear(int dequeue[]);
void deleteFront(int dequeue[]);
void deleteRear(int dequeue[]);
void display(int dequeue[]);
int isFull();
int isEmpty();
void peek(int dequeue[]);
void main()
{

    printf("Enter the size of the queue: ");
    scanf("%d", &max);
    int *dequeue = (int *)malloc(max * sizeof(int));
    int choice;

    while (1)
    {
        printf("\n1. Insert front \n2.Insert rear\n3.Delete front\n4.Delete rear\n5. Display\n6. Is Full?\n7. Is Empty?\n8. Peek\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            insertFront(dequeue);
            break;
        case 2:
            insertRear(dequeue);
            break;
        case 3:
            deleteFront(dequeue);
            break;
        case 4:
            deleteRear(dequeue);
            break;
        case 5:
            display(dequeue);
            break;
        case 6:
            isFull();
            break;
        case 7:
            isEmpty();
            break;
        case 8:
            peek(dequeue);
            break;
        case 9:
            printf("Exiting the program, goodbye!\n");
            free(dequeue);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
void insertRear(int dequeue[]){
    if(isFull()){
        printf("Queue Overflow!\n");
    }else{
        int element;
        if(front==-1){
            front = 0;
            rear = 0;
            printf("Enter a number to enqueue: ");
            scanf("%d", &element);
            dequeue[rear] = element;
            printf("Element %d inserted to the queue!\n", element);
        }
        else{
            rear++;
            printf("Enter a number to enqueue: ");
            scanf("%d", &element);
            dequeue[rear] = element;
            printf("Element %d inserted to the queue!\n", dequeue[rear]);
        }
    }
}

void deleteFront(int dequeue[]){
    if(isEmpty()){
        printf("Queue Underflow!\n");
    }else{
        printf("Element %d removed from the queue!\n", dequeue[front]);
        front++;
        if(front > rear){
            front = -1;
            rear = -1;
        }
    }
}
void display(int dequeue[])
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
            printf("%d ", dequeue[i]);
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
    return (front == -1);
}
void peek(int queue[]){
    if(isEmpty()){
        printf("Queue is empty. nothing to peek!");
    }
    else{
        printf("Front element: %d Rear element: %d",queue[front],queue[rear]);
    }
}
