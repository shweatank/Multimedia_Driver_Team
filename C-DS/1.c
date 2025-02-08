//single linked list
#include<stdio.h>
#include <stdlib.h>

typedef struct ll {
    int data;
    struct ll* next;
} node;

// Insert at the beginning of the list
void insertAtBeginning(int newData, node** head) {
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end of the list
void insertAtEnd(int newData, node** head) {
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete from the beginning of the list
void deleteFromBeginning(node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from the end of the list
void deleteFromEnd(node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) { // If there's only one node
        free(*head);
        *head = NULL;
        return;
    }

    node* temp = *head;
    while (temp->next->next != NULL) { // Traverse to the second last node
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete from a specific position
void deleteFromPosition(int position, node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position == 0) { // Delete the head
        deleteFromBeginning(head);
        return;
    }

    node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Print the list
void printlist(node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;

    // Add some elements to the list
    insertAtBeginning(10, &head);
    insertAtBeginning(20, &head);
    insertAtBeginning(30, &head);
    insertAtEnd(40, &head);

    printf("Original List: ");
    printlist(head);

    // Delete from the beginning
    deleteFromBeginning(&head);
    printf("After deleting from beginning: ");
    printlist(head);

    // Delete from the end
    deleteFromEnd(&head);
    printf("After deleting from end: ");
    printlist(head);

    // Delete from position 1
    deleteFromPosition(1, &head);
    printf("After deleting from position 1: ");
    printlist(head);

    return 0;
}

