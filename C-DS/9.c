//reversing list without using pointers and array
#include <stdio.h>

#define MAX_NODES 100 

typedef struct {
    int data[MAX_NODES];
    int next[MAX_NODES]; 
    int head;           
    int size;             
} LinkedList;

void initializeList(LinkedList* list) {
    list->head = -1;
    list->size = 0;
}

void insert(LinkedList* list, int value) {
    if (list->size >= MAX_NODES) {
        printf("List is full.\n");
        return;
    }

    int newIndex = list->size;  
    list->data[newIndex] = value;
    list->next[newIndex] = -1;  

    if (list->head == -1) {
        list->head = newIndex;
    } else {
        int temp = list->head;
        while (list->next[temp] != -1) {
            temp = list->next[temp];
        }
        list->next[temp] = newIndex;
    }

    list->size++;
}

void reverseList(LinkedList* list) {
    int prev = -1;
    int current = list->head;

    while (current != -1) {
        int nextIndex = list->next[current];
        list->next[current] = prev;
        prev = current;
        current = nextIndex;
    }

    list->head = prev;
}

void printList(LinkedList* list) {
    int temp = list->head;
    while (temp != -1) {
        printf("%d -> ", list->data[temp]);
        temp = list->next[temp];
    }
    printf("NULL\n");
}

int main() {
    LinkedList list;
    initializeList(&list);

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 40);
    insert(&list, 50);

    printf("Original List:\n");
    printList(&list);

    reverseList(&list);

    printf("Reversed List:\n");
    printList(&list);

    return 0;
}

