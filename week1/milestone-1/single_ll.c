/*
Program to perform insert/update/delete operations on Single Linked List.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
void display_ll();
void insert_beg();
void insert_end();
void ins_loc();
void del_beg();
void del_end();
void del_loc();
int count_the_nodes();

int main()
{

    int c;
    do
    {
        printf("\n\n*********MAIN MENU*************\n\n");
        printf("\n1)Display linked list");
        printf("\n2)Insertion at beginning ");
        printf("\n3)Insertion at end ");
        printf("\n4)Insertion at particular location ");
        printf("\n5)Deletion at beginning.");
        printf("\n6)Deletion at end.");
        printf("\n7)Deletion at particular location.");
        printf("\n8)Total number of nodes.");
        printf("\n\n*****************Enter your option****************\n");
        scanf("%d", &c);

        switch(c)
        {
        case 1:
            display_ll();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            ins_loc();
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_end();
            break;
        case 7:
            del_loc();
            break;
        case 8:
        {
            int c=count_the_nodes();
            printf("\n\nThe total number of nodes:%d", c);
        }
        break;
        }

    }
    while(c<12);
    return 0;
}


//display the linked list
void display_ll()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
        printf("linked list is empty\n");
    else
    {
        printf("The Linked List :  \n");
        while(ptr->next!=NULL)
        {
            printf("%d -> ", ptr->data);
            ptr=ptr->next;
        }
        printf("%d", ptr->data);
    }
}



//insert at beginning
void insert_beg()
{
    struct node *new_node;
    int num;
    printf("Enter a new node data.\n");
    scanf("%d", &num);
    new_node= (struct node *)malloc(sizeof(struct node *));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    display_ll();
}



//insert at end
void insert_end()
{
    struct node *new_node, *ptr;
    ptr=start;
    int num;
    printf("Enter a new node data.\n");
    scanf("%d", &num);
    new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(start== NULL)//check if empty
    {
        new_node->next=start;
        start=new_node;
    }
    else
    {
        while(ptr->next!=NULL)//check till ptr points to the last element
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next= NULL;
    }
    display_ll();
}



//insert at a particular location
void ins_loc()
{
    struct node *pptr, *ptr, *new_node;
    pptr=start;
    ptr=start;
    int num,loc,c=0;
    int total_nodes= count_the_nodes();
    new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    printf("\nEnter the location\n");
    scanf("%d", &loc);
    if(loc<=1)
    {
        return insert_beg();
    }
    else if(loc>=total_nodes+1)
    {
        return insert_end();
    }
    else
    {
        printf("Enter a new node data.\n");
        scanf("%d", &num);
        while(ptr->next!=NULL)
        {
            pptr=ptr;
            ptr=ptr->next;
            c++;
            if(c==loc-1)
            {
                pptr->next=new_node;
                new_node->next=ptr;
                break;
            }
        }
    }
    display_ll();
}


//delete at beginning
void del_beg()
{
    struct node *temp;
    temp=start;
    start=start->next;
    free(temp);
    display_ll();
}


//delete at end
void del_end()
{
    struct node *pptr, *ptr;//pptr is previous to ptr
    pptr=start;
    ptr=start;
    while(ptr->next!=NULL)
    {
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=NULL;
    free(ptr);
    display_ll();
}



//delete at particular location
void del_loc()
{
    struct node *pptr, *ptr;
    ptr=start;
    int loc,c=0;
    int total_nodes= count_the_nodes();
    printf("enter the location to be deleted\n");
    scanf("%d", &loc);
    if(loc<=1)
        return del_beg();
    else if(loc>total_nodes)
        return del_end();
    else
    {
        while(ptr->next!=NULL)
        {
            c++;
            if(c==loc)
                break;
            pptr=ptr;
            ptr=ptr->next;
        }
        pptr->next=ptr->next;
        free(ptr);
    }
    display_ll();
}


//count the number of nodes in a linked list
int count_the_nodes()
{
    struct node *ptr;
    ptr=start;
    int c=0;
    if(start==NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            c++;
        }
    }
    return c;
}
