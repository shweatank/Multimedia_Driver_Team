//Finding middle node
#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
    int data;
    struct ll* next;
}node;
void insertAtBeg(int data,node **head)
{
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
void insertAtEnd(int data,node **head)
{
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
node* middleNode(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node *slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void print(node *head)
{
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
    node *head=NULL;
    insertAtBeg(10,&head);
    insertAtBeg(50,&head);
    insertAtBeg(40,&head);
    insertAtBeg(20,&head);
    insertAtEnd(15,&head);
    insertAtEnd(30,&head);
    insertAtEnd(20,&head);
    print(head);
    node *middle=middleNode(head);
    if(middle!=NULL)
    {
        printf("Middle node is:%d\n",middle->data);
    }
    else
    {
        printf("List is empty.\n");
    }
    
    
}




