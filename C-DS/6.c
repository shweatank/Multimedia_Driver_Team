//Heterogenous list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    void* data;         
    struct Node* next;   
};

struct Node* createNode(void* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head, void (*printFunc)(void*)) {
    while (head != NULL) {
        printFunc(head->data); 
        head = head->next;
    }
    printf("\n");
}

void printInt(void* data) {
    printf("%d -> ", *(int*)data);
}

void printFloat(void* data) {
    printf("%.2f -> ", *(float*)data);
}

int main() {
    struct Node* head = NULL;

    int a = 10;
    float b = 20.5;

    head = createNode(&a);            
    head->next = createNode(&b);       

    printf("Integer list: ");
    printList(head, printInt);

    printf("Float list: ");
    printList(head, printFloat);

    return 0;
}

