#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1, max;
void enqueue(int queue[]);
void dequeue(int queue[]);
void display(int queue[]);
int isFull();
int isEmpty();
void peek(int queue[]);

void main()
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
            if (isFull())
                printf("Queue is full!\n");
            else
                printf("Queue is not full.\n");
            break;
        case 5:
            if (isEmpty())
                printf("Queue is empty!\n");
            else
                printf("Queue is not empty.\n");
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
}

int isFull() {
    return (front == (rear + 1) % max);
}

int isEmpty() {
    return (front == -1);
}

void peek(int queue[]) {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek!\n");
    } else {
        printf("Front element: %d, Rear element: %d\n", queue[front], queue[rear]);
    }
}

void enqueue(int queue[]) {
    if (isFull()) {
        printf("Queue Overflow!\n");
    } else {
        int element;
        printf("Enter a number to enqueue: ");
        scanf("%d", &element);
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % max;
        }
        queue[rear] = element;
        printf("Element %d inserted to the queue!\n", element);
    }
}

void dequeue(int queue[]) {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
    } else {
        printf("Element %d removed from the queue!\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
}

void display(int queue[]) {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Elements in the queue are: ");
        int i = front;
        do {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % max;
        } while (1);
        printf("\n");
    }
}