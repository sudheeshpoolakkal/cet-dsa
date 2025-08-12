#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, max;

void insertFront(int deque[]);
void insertRear(int deque[]);
void deleteFront(int deque[]);
void deleteRear(int deque[]);
void display(int deque[]);
int isFull();
int isEmpty();
void peek(int deque[]);

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &max);

    int *deque = (int *)malloc(max * sizeof(int));
    if (!deque) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;

    while (1) {
        printf("\n1. Insert front\n2. Insert rear\n3. Delete front\n4. Delete rear\n");
        printf("5. Display\n6. Is Full?\n7. Is Empty?\n8. Peek\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertFront(deque);
            break;
        case 2:
            insertRear(deque);
            break;
        case 3:
            deleteFront(deque);
            break;
        case 4:
            deleteRear(deque);
            break;
        case 5:
            display(deque);
            break;
        case 6:
            if (isFull())
                printf("Queue is full!\n");
            else
                printf("Queue is not full.\n");
            break;
        case 7:
            if (isEmpty())
                printf("Queue is empty!\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 8:
            peek(deque);
            break;
        case 9:
            printf("Exiting the program, goodbye!\n");
            free(deque);
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

void insertRear(int deque[]) {
    if (isFull()) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % max; // circular increment
        }
        int element;
        printf("Enter a number to enqueue: ");
        scanf("%d", &element);
        deque[rear] = element;
        printf("Element %d inserted to the queue!\n", element);
    }
}

void insertFront(int deque[]) {
    if (isFull()) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            front = (front - 1 + max) % max; // circular decrement
        }
        int element;
        printf("Enter an element to enqueue: ");
        scanf("%d", &element);
        deque[front] = element;
        printf("Element %d inserted to the queue!\n", element);
    }
}

void deleteRear(int deque[]) {
    if (isEmpty()) {
        printf("Queue underflow!\n");
    } else {
        printf("Element %d removed from the queue!\n", deque[rear]);
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            rear = (rear - 1 + max) % max; // circular decrement
        }
    }
}

void deleteFront(int deque[]) {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
    } else {
        printf("Element %d removed from the queue!\n", deque[front]);
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            front = (front + 1) % max; // circular increment
        }
    }
}

void display(int deque[]) {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Elements in the queue are: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear)
                break;
            i = (i + 1) % max;
        }
        printf("\n");
    }
}

int isFull() {
    return (front == (rear + 1) % max);
}

int isEmpty() {
    return (front == -1);
}

void peek(int deque[]) {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek!\n");
    } else {
        printf("Front element: %d | Rear element: %d\n", deque[front], deque[rear]);
    }
}
