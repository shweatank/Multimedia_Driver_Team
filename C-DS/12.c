//merging linked list using merge sort
#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
    int data;
    struct ll* next;
}node;
void insert_at_beg(int data,node** head)
{
    node* newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
void insert_at_end(int data,node** head)
{
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        printf("Error in memory allocation\n");
        return;
    }
    node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void splitlist(node *head,node **firsthalf,node **secondhalf)
{
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    *firsthalf=head;
    *secondhalf=slow->next;
    slow->next=NULL;
    
}
node* mergeSortedList(node *first,node *second)
{
    if(!first)
    {
        return second;
    }
    if(!second)
    {
        return first;
    }
    node *result=NULL;
    if(first->data<=second->data)
    {
        result=first;
        result->next=mergeSortedList(first->next,second);
    }
    else
    {
        result=second;
        result->next=mergeSortedList(first,second->next);
    }
    return result;
}
void mergeSort(node** head)
{
    if(!(*head)||!((*head)->next))
    {
        return;
    }
    node *firsthalf;
    node *secondhalf;
    splitlist(*head,&firsthalf,&secondhalf);
    mergeSort(&firsthalf);
    mergeSort(&secondhalf);
    *head=mergeSortedList(firsthalf,secondhalf);
}
void printList(node *head)
{
    while(head !=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
    node* head=NULL;
    insert_at_beg(40,&head);
    insert_at_beg(30,&head);
    insert_at_beg(50,&head);
    insert_at_beg(10,&head);
    insert_at_beg(32,&head);
    insert_at_beg(65,&head);
    insert_at_beg(70,&head);
    printf("Original Linked List:");
    printList(head);
    mergeSort(&head);
    printf("Sorted List:");
    printList(head);
    while(head!=NULL)
    {
        node* temp=head;
        head=head->next;
        free(temp);
        
    }
    return 0;
}





