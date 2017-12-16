/*
Program to perform insert/update/delete operations on Circular Linked List.
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

//Driver Program
void main()
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
}


//display the linked list
void display_ll()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        printf("\n\nTHE LINKED LIST IS: \n");
        while(ptr->next!=start)
        {
            printf("%d -> ", ptr->data);
            ptr=ptr->next;
        }
        printf("%d  ->  %d\n\n", ptr->data, start->data);
    }
}



//insert at beginning
void insert_beg()
{
    struct node *new_node, *ptr;
    int d;
    printf("Enter a new node data.\n");
    scanf("%d", &d);
    new_node= (struct node *)malloc(sizeof(struct node *));
    ptr=start;
    new_node->data=d;
    if(start==NULL)
    {
        start=new_node;
        new_node->next=start;
    }
    else
    {
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next=start;
        start=new_node;
    }
    display_ll();
}



//insert at end
void insert_end()
{
    struct node *new_node, *ptr;
    int d;
    printf("\nEnter the data:  ");
    scanf("%d", &d);
    new_node= (struct node *)malloc(sizeof(struct node *));
    ptr=start;
    new_node->data=d;
    if(start==NULL)
    {
        start=new_node;
        new_node->next=start;
    }
    else
    {
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next=start;
    }
    display_ll();
}



//insert at a particular location
void ins_loc()
{
    struct node *new_node, *pptr, *ptr;
    ptr=start;
    int loc, d,k=0;
    new_node=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the location: ");
    scanf("%d", &loc);
    if(loc<=1)
    {
        return insert_beg();
    }
    else if(loc>count_the_nodes())
    {
        return insert_end();
    }
    else
    {
        printf("\nEnter a new node data:  ");
        scanf("%d", &d);
        new_node->data=d;
        while(ptr->next!=start)
        {
            pptr=ptr;
            ptr=ptr->next;
            k++;
            if(k==(loc-1))
            {
                break;
            }
        }
        pptr->next=new_node;
        new_node->next=ptr;
    }
    display_ll();
}


//delete at beginning
void del_beg()
{
    struct node *pptr, *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr=ptr;
    ptr=ptr->next;
    start=start->next;
    pptr->next=start;
    free(ptr);
    display_ll();
}



//delete at end
void del_end()
{
    struct node *pptr, *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=start;
    free(ptr);
    display_ll();
}




//delete at particular location
void del_loc()
{
    struct node *pptr, *ptr;
    ptr=start;
    int loc,k=0;
    printf("\nEnter the location: ");
    scanf("%d", &loc);
    if(loc<=1)
        return del_beg(start);
    else if(loc>count_the_nodes())
        return del_end(start);
    else
    {
        while(ptr->next!=start && k!=(loc-1))
        {
            k++;
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
    struct node *ptr=start;
    int c=0;
    do
    {
        ptr=ptr->next;
        c++;
    }
    while(ptr!=start);
    return c;
}
