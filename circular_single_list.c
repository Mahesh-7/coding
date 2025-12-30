#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; // Points to itself (circular link)
    return newNode;
}

// Function to append a node at the end of the circular linked list
void append(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode; // First node in the list
    } else {
        struct Node* temp = *head;

        // Traverse the list until the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Link the last node to the new node
        temp->next = newNode;
        newNode->next = *head; // Make it circular again
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Function to delete the first node in the list
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Set the head to the next node
        struct Node* firstNode = *head;
        *head = (*head)->next;

        // Link the last node to the new head
        temp->next = *head;

        free(firstNode); // Free memory of the deleted node
    }
}

// Function to delete the last node in the list
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;

        // Traverse to the second last node
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = *head; // Set the second last node's next to head
        free(temp); // Free the last node
    }
}

int main() {
    struct Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("Circular Linked List: ");
    display(head);

    deleteFirst(&head);
    printf("After deleting the first node: ");
    display(head);

    deleteLast(&head);
    printf("After deleting the last node: ");
    display(head);

    return 0;
}
