//comparison of 2 lists
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

int compareLists(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return 0; 
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == NULL && head2 == NULL) {
        return 1; 
    }
    return 0;
}
	 
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insertNode(&head1, 10);
    insertNode(&head1, 20);
    insertNode(&head1, 30);

    insertNode(&head2, 10);
    insertNode(&head2, 20);
    insertNode(&head2, 30);

    printf("Linked List 1: ");
    printList(head1);
    printf("Linked List 2: ");
    printList(head2);

    if (compareLists(head1, head2)) {
        printf("The linked lists are equal.\n");
    } else {
        printf("The linked lists are not equal.\n");
    }

    while (head1 != NULL) {
        struct Node* temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL) {
        struct Node* temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}

