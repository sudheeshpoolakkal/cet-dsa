#include<stdio.h>
#include<stdlib.h>
int front =-1, rear=-1, max;
void enqueue(int queue[]);
void dequeue(int queue[]);
void display(int queue[]);
void main()
{

    printf("Enter the size of the queue: ");
    scanf("%d", &max);
    int *queue = (int *)malloc(max * sizeof(int));
    int choice;
    
    while (1)
    {
        printf("1.Enqueue \n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4)
        {
            printf("Exiting the program, goodbye!\n");
            free(queue);
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
            enqueue(queue);
            break;

        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
void enqueue(int queue[]){
    if(front == (rear+1)%max){
        printf("Queue Overflow!\n");
    }else{
        int element;
        if(front==-1){
            front = 0;
            rear = 0;
            printf("Enter a number to enqueue: ");
            scanf("%d", &element);
            queue[rear] = element;
            printf("Element %d inserted to the queue!\n", element);
        }
        else{
            rear = (rear + 1) % max;
            printf("Enter a number to enqueue: ");  
            scanf("%d", &element);
            queue[rear] = element;
            printf("Element %d inserted to the queue!\n", queue[rear]);
        }
    }
}

void dequeue(int queue[]){
    if(front==-1){
        printf("Queue Underflow!\n");
    }else{
        printf("Element %d removed from the queue!\n", queue[front]);
        
        if(front == rear){
            front = rear = -1;  
        } else{
            front = (front + 1) % max;
        }
    }
}
void display(int queue[])
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Elements in the queue are :");
       int i = front;
       while(1){
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % max;
       }

        printf("\n");
    }
}