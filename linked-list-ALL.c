#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global pointers
struct node *head = NULL;
struct node *tail = NULL;

// Function to create a new node
struct node *createNode() {
    int data;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (O(1))
void insertEnd() {
    struct node *newNode = createNode();
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    printf("Node added at the end!\n");
}

// Insert at beginning (O(1))
void insertBeginning() {
    struct node *newNode = createNode();
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printf("Node inserted at the beginning!\n");
}

// Insert at a given position
void insertPosition() {
    int position;
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }

    if (position == 1) {
        insertBeginning();
        return;
    }

    struct node *newNode = createNode();
    struct node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        tail = newNode;
    }
    printf("Node inserted at position %d!\n", position);
}

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }
    printf("First element with data %d deleted\n", temp->data);
    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty, cannot delete!\n");
        return;
    }
    if (head->next == NULL) {
        printf("Last node with data %d deleted\n", head->data);
        free(head);
        head = tail = NULL;
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Last node with data %d deleted\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    tail = temp;
}

// Delete node at a given position
void deletePosition() {
    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }
    if (head == NULL) {
        printf("List is empty, cannot delete!\n");
        return;
    }
    if (position == 1) {
        deleteFirst();
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of bounds!\n", position);
        return;
    }

    struct node *nodeDelete = temp->next;
    temp->next = nodeDelete->next;

    if (nodeDelete->next == NULL) {
        tail = temp;
    }

    printf("Node with data %d at position %d deleted.\n", nodeDelete->data, position);
    free(nodeDelete);
}

// Delete the entire list
void deleteWholeList() {
    struct node *temp = head;
    int count = 0;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
        count++;
    }
    head = tail = NULL;
    printf("Whole linked list deleted. %d nodes were freed.\n", count);
}

// Print linked list
void printList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Count nodes
void countNodes() {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of elements: %d\n", count);
}

// Menu
void displayMenu() {
    printf("\n========= LINKED LIST OPERATIONS =========\n");
    printf("1. Insert node at end\n");
    printf("2. Insert node at beginning\n");
    printf("3. Insert node at a position\n");
    printf("4. Delete first node\n");
    printf("5. Delete last node\n");
    printf("6. Delete node from a position\n");
    printf("7. Delete whole linked list\n");
    printf("8. Print list\n");
    printf("9. Count nodes\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    printf("Single Linked List Implementation\n");
    printf("=================================\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertEnd(); break;
            case 2: insertBeginning(); break;
            case 3: insertPosition(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deletePosition(); break;
            case 7: deleteWholeList(); break;
            case 8: printList(); break;
            case 9: countNodes(); break;
            case 0:
                printf("Cleaning up memory...\n");
                deleteWholeList();
                printf("Program terminated successfully!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again\n");
        }
    }
}
