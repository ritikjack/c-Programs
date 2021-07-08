#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
}*head=NULL;

typedef struct node node;

void createNode();
void display();

void beginsert();
void lastinsert();
void randominsert();

void begdelete();
void lastdelete();
void randomdelete();

void main()
{
    createNode();
    display();
    beginsert();
}

void createNode()
{
    int i=1,n,t;
    node *ptr,*last;
    
    ptr=(node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("\nOVWERFLOW.\n");
    }
    else
    {
        printf("enter total no. of data:\n");
        scanf("%d",&n);
        
        printf("\nenter %d data:\n",i);
        scanf("%d",&t);
        
        ptr->data=t;
        ptr->next=NULL;
        ptr->prev=NULL;
        head=ptr;
        
        last=ptr;
        for(i=2;i<=n;i++)
        {
            printf("\nenter %d data:\n",i);
            scanf("%d",&t);
            
            ptr=(node *)malloc(sizeof(node));
            ptr->data=t;
            ptr->next=NULL;
            
            ptr->prev=last;
            last->next=ptr;
            last=ptr;
        }
        printf("\nnode created.");
    }
}

void display()
{
    node *ptr;
    
    if(head==NULL)
    {
        printf("\nlist is empty.");
    }
    else
    {
        printf("\npriting data:\n");
        ptr=head;
        while(ptr->next!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
    
}

void beginsert()
{
    node *ptr;
    int item;
    
    ptr=(node *)malloc(sizeof(node));
    
    if(ptr==NULL)
    {
        printf("\nOVERFLOW.");
    }
    else
    {
        printf("\nenter data:\n");
        scanf("%d",&item);
        
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            
            head=ptr;
        }
        else
        {
            ptr->next=head;
            head->next->prev=ptr;
            ptr->prev=NULL;
            head=ptr;
            
        }
        printf("\nnode inserted at begining.\n");
        display();
    }
}
