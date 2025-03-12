//Standard Linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insertBeg(int ndata, Node** head) {
    Node* Newnode = malloc(sizeof(Node));
    Newnode->data = ndata;
    Newnode->next = *head;
    *head = Newnode;
}

void insertEnd(int ndata, Node** head) {
    Node* Newnode = malloc(sizeof(Node));
    Node* temp = *head;
    Newnode->data = ndata;
    Newnode->next = NULL;

    if (*head == NULL) {  // If list is empty
        *head = Newnode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = Newnode;
}

void reverse(Node** head) {
    Node* temp1 = *head;
    Node* temp2 = NULL;
    while (temp1 != NULL) {
        Node* temp = temp1->next;
        temp1->next = temp2;
        temp2 = temp1;
        temp1 = temp;
    }
    *head = temp2;
}

void deleteNode(int data, Node** head) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == data) {  // Deleting head node
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {  // Find node to delete
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Data not found

    prev->next = temp->next;  // Unlink node
    free(temp);
}

void printlist(Node* temp) {
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insertBeg(10, &head);
    insertBeg(18, &head);
    insertBeg(22, &head);
    insertBeg(16, &head);
    insertEnd(24, &head);
    insertEnd(15, &head);
    insertEnd(21, &head);
    insertEnd(28, &head);
    insertEnd(13, &head);

    printf("Original list: ");
    printlist(head);

    deleteNode(22, &head);
    printf("\nList after deleting one element: ");
    printlist(head);

    reverse(&head);
    printf("\nList after reversal: ");
    printlist(head);
    
    printf("\n");
    return 0;
}

