/*
Program to perform insert/update/delete operations on BINARY SEARCH TREE.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* createNewNode(int data);
struct node* insert(struct node* root, int data);
struct node* search(struct node* root, int data);
struct node* delete(struct node* root, int data);
void update(struct node* root,int dataToBeUpdated, int dataToUpdated);
struct node* findMIN(struct node* root);
void display(struct node* root);
void inorder(struct node* root);

//Driver Program
void main()
{
    struct node* root = NULL;
    root = insert(root, 12);
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 13);
    insert(root, 17);
    insert(root, 1);
    insert(root, 9);
    insert(root, 14);
    insert(root, 20);
    insert(root, 8);
    insert(root, 11);
    insert(root, 18);
    printf("Original tree\n");
    display(root);
    printf("\n\nSearching %d in BST\n", 18);
    if(search(root, 18))
    {
        printf("18 is present\n\n");
    }
    printf("Minimum node\n");
    struct node* temp = findMIN(root);
    printf("%d\n\n", temp->data);

    //Deleting leaf node
    printf("After deleting leaf node\n");
    delete(root, 8);
    display(root);

    //Deleting single child node
    printf("\n\nAfter deleting node with one child\n");
    delete(root, 7);
    display(root);

    //Deleting both children
    printf("\n\nAfter deleting node with 2 children\n");
    delete(root, 15);
    display(root);

    update(root, 14, 41);
    printf("\n\nAfter updating 14 to 41, the BST is as below\n");
    display(root);
    printf("\n\n");
}

struct node* createNewNode(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

//Insertion
struct node* insert(struct node* root, int data)
{
    if(root == NULL)
    {
        return createNewNode(data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right,data);
    }
    else
    {
        printf("Data already present");
    }
}

//Searching
struct node* search(struct node* root, int data)
{
    if(root == NULL || root->data == data)
    {
        return root;
    }

    if(data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        if(data > root->data)
        {
            return search(root->right, data);
        }
    }
}

//Deletion
struct node* delete(struct node* root, int data)
{
    if(root == NULL)
    {
        return root;
    }
    if(data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else
    {
        //leaf node
        if(root->left == NULL && root->right == NULL)
        {
            struct node* temp = root;
            free(root);
            root=NULL;
        }
        //single right node
        else if(root->left == NULL)
        {
            root = root->right;
        }
        //single left node
        else if(root->right == NULL)
        {
            root = root->left;
        }
        //having both children
        else
        {
            struct node* temp = findMIN(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
        return root;
    }
}

//Minimum in a BST
struct node* findMIN(struct node* root)
{
    int min = root->data;
    if(root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMIN(root->left);
    }
}

//Updation
void update(struct node* root,int dataToBeUpdated, int dataToUpdated)
{
    delete(root, dataToBeUpdated);
    insert(root, dataToUpdated);
}

//Display
void display(struct node* root)
{
    inorder(root);
}

//Inorder Traversal
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}
