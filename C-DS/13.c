//Sorting using merge sort
#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
    int data;
    struct ll* next;
}node;

void insert_at_beg(node ** head,int newdata)
{
    node* newnode=malloc(sizeof(node));
    newnode->data=newdata;
    newnode->next=*head;
    *head=newnode;
}
int countNodes(node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
void copytoarray(node *head,int *arr)
{
    int i=0;
    while(head!=NULL)
    {
        arr[i++]=head->data;
        head=head->next;
    }
}
void copyfromArray(node *head,int *arr)
{
    int i=0;
    while(head!=NULL)
    {
        head->data=arr[i++];
        head=head->next;
    }
}
void BubbleSort(int *arr,int n)
{
    int i=0,j=0,temp;
    
    for(i=0;i<n-1;i++)
    {
        int swapped=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0)
        {
            break;
        }
    }
}
void printList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    node* head=NULL;
    insert_at_beg(&head, 30);
    insert_at_beg(&head, 10);
    insert_at_beg(&head, 50);
    insert_at_beg(&head, 20);
    insert_at_beg(&head, 40);

    printf("Original Linked List:\n");
    printList(head);

    // Count nodes and allocate an array
    int n = countNodes(head);
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation for array failed.\n");
        return 1;
    }

    // Copy linked list data to array, sort it, and copy it back
    copytoarray(head, arr);
    BubbleSort(arr, n);
    copyfromArray(head, arr);

    printf("\nSorted Linked List:\n");
    printList(head);

    // Free allocated memory for the array and linked list
    free(arr);
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


