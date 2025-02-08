//reversing list using arrays
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void reverseListUsingArray(Node* head) {
    if (head == NULL) return;

    int values[100]; 
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        values[count++] = temp->data;
        temp = temp->next;
    }

    for (int i = 0, j = count - 1; i < j; i++, j--) {
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    temp = head;
    int index = 0;
    while (temp != NULL) {
        temp->data = values[index++];
        temp = temp->next;
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Original List:\n");
    printList(head);

    reverseListUsingArray(head);

    printf("Reversed List:\n");
    printList(head);
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

