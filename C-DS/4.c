// nth node from the end of the list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* findNthFromEnd(struct Node* head, int n) {
    struct Node* first = head;
    struct Node* second = head;

    for (int i = 0; i < n; i++) {
        if (first == NULL) {
            printf("The list has fewer than %d nodes.\n", n);
            return NULL;
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second; 
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    printf("Linked List: ");
    printList(head);

    int n = 2; 
    struct Node* result = findNthFromEnd(head, n);

    if (result != NULL) {
        printf("The %dth node from the end is: %d\n", n, result->data);
    }

    return 0;
}

