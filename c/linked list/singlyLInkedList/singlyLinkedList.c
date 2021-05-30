#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

typedef struct node node;

void createnode();
void display();

void begInsert();
void lastInsert();
void randomInsert();

void begdelete();
void lastdelete();
void randomdelete();

void main()
{
    createnode();
    display();
    // begInsert();
    // lastInsert();
    // randomInsert();
    
    // begdelete();
    // lastdelete();
    // randomdelete();
}

void createnode()
{
    int n,i=0,t;
    node *ptr,*temp;
    
    printf("enter total no. of data\n");
    scanf("%d",&n);
    
    printf("enter %d data\n",i+1);
    scanf("%d",&t);
    
    
    ptr=(node *)malloc(sizeof(node));
    ptr->data=t;
    ptr->next=NULL;
    
    head=ptr;
    
    for(i=1;i<n;i++)
    {
        printf("enter %d data:\n",i+1);
        scanf("%d",&t);
        temp=(node*)malloc(sizeof(node));
        temp->data=t;
        temp->next=NULL;
        ptr->next=temp;
        ptr=temp;
    }
}

void display()
{
    node *ptr;
    ptr=head;
    
    if(ptr==NULL)
    {
        printf("EMPTY LIST\n");
    }
    else
    {
        printf("printing data:\n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}


void begInsert()
{
    node *temp;
    int item;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nenter data to insert in begining:\n");
        scanf("%d",&item);
        
        temp=(node *)malloc(sizeof(node));
        temp->data=item;
        
        temp->next=head;
        
        head=temp;
        
        printf("\nNode Inserted at begining.\n");
        display();
    }
}

void lastInsert()
{
    node *ptr,*temp;
    int item;
    
    ptr=(node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOEW\n");
    }
    else
    {
        printf("\nenter data to insert in the last:");
        scanf("%d",&item);
        
        ptr->data=item;

        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            
            temp->next=ptr;
            ptr->next=NULL;
        }
        printf("\ndata inserted in the last.\n");
        display();
    }
}

void randomInsert()
{
    node *ptr,*temp;
    int i=0,loc,item;
    
    ptr=(node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOEW.");
    }
    else
    {
        printf("\nenter location after that you want to insert new data:\n");
        scanf("%d",&loc);
        
        temp=head;
        
        for(i=1;i<loc;i++)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\ncan't insert.\n");
            return;
        }
        else
        {
            printf("\nenter the data:\n");
            scanf("%d",&item);
            
            ptr->data=item;
            
            ptr->next=temp->next;
            temp->next=ptr;
            
            printf("\nnode inserted after %d location.\n",loc);
            display();
        }
    }
}

void begdelete()
{
    node *ptr;
    
    ptr=head;
    
    if(ptr==NULL)
    {
        printf("\nUNDERFLOW.\n");
    }
    else
    {
        head=ptr->next;
        free(ptr);
        printf("\nnode deleted at begining.\n");
        display();
    }
}

void lastdelete()
{
    node *ptr,*prev;
    
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nUNDERFLOW.\n");

    }
    else
    {
        while(ptr!=NULL)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        
        prev->next=NULL;
        free(ptr);
        printf("\nnode deleted from last.\n");
        display();
    }
}


void randomdelete()
{
    node *ptr,*prev;
    int i,loc;
    
    if(head==NULL)
    {
        printf("\nlist is empty.");
    }
    else
    {
        printf("\nenter the location which data you want to delete:\n");
        scanf("%d",&loc);
        
        ptr=head;
        for(i=1;i<loc;i++)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("\nwrong location.");
        }
        else
        {
            prev->next=ptr->next;
            free(ptr);
            printf("\ndata deleted of %d location.\n",loc);
            display();
        }
    }
}
