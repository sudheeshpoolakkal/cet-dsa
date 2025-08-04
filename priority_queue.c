#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element items[MAX];
    int size;
} PriorityQueue;

// Function prototypes
void insert(PriorityQueue *pq, int data, int priority);
void deleteHighestPriority(PriorityQueue *pq);
void display(PriorityQueue *pq);
int isFull(PriorityQueue *pq);
int isEmpty(PriorityQueue *pq);
Element peek(PriorityQueue *pq);

int main() {
    PriorityQueue pq;
    pq.size = 0;
    int choice, data, priority;

    while (1) {
        printf("\n1. Insert\n2. Delete Highest Priority\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (isFull(&pq)) {
                printf("Queue is full!\n");
                break;
            }
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority (lower number = higher priority): ");
            scanf("%d", &priority);
            insert(&pq, data, priority);
            break;
        case 2:
            deleteHighestPriority(&pq);
            break;
        case 3:
            display(&pq);
            break;
        case 4:
            if (!isEmpty(&pq)) {
                Element top = peek(&pq);
                printf("Highest priority element: %d (priority: %d)\n", top.data, top.priority);
            } else {
                printf("Queue is empty!\n");
            }
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
void insert(PriorityQueue *pq, int data, int priority) {
    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = pq->size - 1;

    // Shift elements to the right to maintain ascending order by priority
    while (i >= 0 && pq->items[i].priority > priority) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }

    pq->items[i + 1] = newElement;
    pq->size++;

    printf("Inserted %d with priority %d\n", data, priority);
}

void deleteHighestPriority(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue underflow!\n");
        return;
    }

    printf("Deleted element: %d (priority: %d)\n", pq->items[0].data, pq->items[0].priority);

    // Shift all elements left
    for (int i = 1; i < pq->size; i++) {
        pq->items[i - 1] = pq->items[i];
    }
    pq->size--;
}

void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Priority Queue contents (ascending priority):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Data: %d\tPriority: %d\n", pq->items[i].data, pq->items[i].priority);
    }
}

Element peek(PriorityQueue *pq) {
    return pq->items[0];  // Lowest priority value = highest priority
}

int isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

