//Generic linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;            
    struct Node* next;     
} Node;

Node* createNode(void* data, size_t dataSize) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = malloc(dataSize);  
    if (!newNode->data) {
        printf("Data memory allocation failed.\n");
        free(newNode);
        return NULL;
    }
    memcpy(newNode->data, data, dataSize);  
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, void* data, size_t dataSize) {
    Node* newNode = createNode(data, dataSize);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printIntList(Node* head) {
    printf("Integer List: ");
    while (head != NULL) {
        printf("%d -> ", *(int*)head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void printStringList(Node* head) {
    printf("String List: ");
    while (head != NULL) {
        printf("%s -> ", (char*)head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp->data);  
        free(temp);        
    }
}

int main() {
    Node* intList = NULL;   
    Node* stringList = NULL; 

    int intData[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) {
        insertNode(&intList, &intData[i], sizeof(int));
    }

    char* stringData[] = {"Hello", "World", "Generic", "Linked", "List"};
    for (int i = 0; i < 5; i++) {
        insertNode(&stringList, stringData[i], strlen(stringData[i]) + 1);
    }

    printIntList(intList);
    printStringList(stringList);

    freeList(intList);
    freeList(stringList);

    return 0;
}

