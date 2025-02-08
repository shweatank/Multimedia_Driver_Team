//Creating and detecting loop
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

void createLoop(struct Node* head, int position) {
    if (head == NULL || position <= 0) return;

    struct Node* loopNode = NULL;
    struct Node* temp = head;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    if (loopNode) {
        temp->next = loopNode; 
    }
}

int detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;        
        fast = fast->next->next;  

        if (slow == fast) {
            return 1;  
        }
    }
    return 0; 
}

int main() {
    struct Node* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    createLoop(head, 2);

    if (detectLoop(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop in the linked list.\n");
    }

    return 0;
}

