/*
Program to perform insert/update/delete operations on TRIE TREE.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHAR_TO_INT(ch) ((int)ch - (int)'a')

struct node
{
    //represents at which node, the entire word is completed
    int isCompleteWord;
    struct node* nextAlpha[26];//maximum next nodes set as 26 only(26 alphabets)//can be more
};

//Creating new node
struct node* createNewTrieNode()
{
    int i=0;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->isCompleteWord = 0;
    for(i=0; i<26; i++)
    {
        new_node->nextAlpha[i] = NULL;
    }
}

//Insertion
struct node* insert(struct node* root, char *str)
{
    struct node* new_node;
    int i, j=0;
    for(i=0; i<strlen(str); i++)
    {
        char ch = str[i];
        //if the position at which the character's node should have been present(i.e for 'b': nextAlpha[66-65]=nextAlpha[1]) is not present or equal to NULL.
        int pos = CHAR_TO_INT(ch);
        if(root->nextAlpha[pos] == NULL)
        {
            new_node = createNewTrieNode(root);
            //before it was NULL, atleast now point root's that position to new_node
            root->nextAlpha[pos] = new_node;
            //root will point to new_node;
            root = new_node;
        }
        else
        {
            root = root->nextAlpha[pos];
        }
    }
    root->isCompleteWord++;
    return root;
}

//Searching
int search(struct node* root, char *str)
{
    int i=0;
    char ch;
    for(i=0; i<strlen(str); i++)
    {
        ch = str[i];
        int pos = CHAR_TO_INT(ch);
        if(root->nextAlpha[pos] != NULL)
        {
            root = root->nextAlpha[pos];
        }
        else
        {
            return -1;
        }
    }
    return root->isCompleteWord;
}

struct node* isLeaf(struct node* ptr)
{
    int i;
    for(i=0; i<26; i++)
    {
        if(ptr->nextAlpha[i] != NULL)
        {
            return NULL;
        }
    }
}

//Deletion
int delete(struct node* root, char *str)
{
    int i;
    char ch;
    int len = strlen(str);
    struct node* prevPtrs[len+1] ;
    prevPtrs[0] = root;
    for(i=1; i<=len; i++)
    {
        ch = str[i-1];
        int pos = CHAR_TO_INT(ch);
        if(root->nextAlpha[pos] != NULL)
        {
            prevPtrs[i] = root->nextAlpha[pos];
            printf("completeNode: %d\n\n", prevPtrs[i]->isCompleteWord);
            root = root->nextAlpha[pos];
        }
        else
        {
            return -1;
        }
    }
    root->isCompleteWord = 0;

    //now backtrack & remove all the nodes in that path having isCompleteNode = 0, and it is a 'leaf' node meaning
    //that this path is also not extending into any other words.
    if(!isLeaf(root))
    {
        for(i=len; i>0; i--)
        {
            ch = str[i-1];
            int pos = CHAR_TO_INT(ch);
            if(prevPtrs[i]->isCompleteWord != 0)
            {
                break;
            }
            else
            {
                struct node* temp = prevPtrs[i];
                prevPtrs[i-1]->nextAlpha[pos] = NULL;
                if(i>1)
                {
                    free(temp);
                }
            }
        }
    }
    return 1;
}



//Updation
struct node* update(struct node* root, char *dataToBeUpdated, char *dataToUpdate)
{
    if(delete(root, dataToBeUpdated)>0)
    {
        return insert(root, dataToUpdate);
    }
}

//Driver Program
void main()
{
    struct node* root;
    int i;
    struct node* temp;
    char str[8][14];
    strcpy(str[0], "hello");
    strcpy(str[1], "healthy");
    strcpy(str[2], "hamlet");
    strcpy(str[3], "heal");
    strcpy(str[4], "simsons");
    strcpy(str[5], "sister");
    //these leave for updation
    strcpy(str[6], "master");
    strcpy(str[7], "manage");

    //create a root node
    root = createNewTrieNode();

    //Insertion
    printf("****************TrieTree Insertion****************\n");
    for(i=0; i<6 ;i++)
    {
        temp = insert(root, str[i]);
        //Should return 1 - successfully inserted
        if(temp->isCompleteWord > 0)
        {
            printf("'%s' inserted\n", str[i]);
        }
    }
    printf("\n");

    //Searching
    printf("****************TrieTree Searching****************\n");
    if(search(root, str[1]) > 0)
    {
        printf("String '%s' found\n\n", str[1]);
    }
    else
    {
        printf("String %s not found\n\n", str[1]);
    }

    //Deletion Case 1: After deleting 'healthy', 'heal' shouldn't get deleted(deleting the nodes from end till you get another valid node in the same path)
    //value of completeNode = tells us till which nodes are actually in tree.
    printf("*************TrieTree Deletion: CASE 1************\n");
    printf("Trying to delete string '%s'.....\n", str[1]);
    if(delete(root, str[1]) > 0)
    {
        printf("String '%s' Deleted\n", str[1]);
        printf("Searching '%s' in TrieTree........\n", str[3]);
        if(search(root, str[3]) > 0)
        {
            printf("/'%s' found\n\n", str[3]);
        }
        else
        {
            printf("'%s' not found\n\n", str[3]);
        }
    }
    else
    {
        printf("\n\nString '%s' not found", str[1]);
    }

    //Deletion Case 2: Deleting a string which lies in the same path as another string longer in length(ex. deleting 'heal' when 'healthy' is present)
    printf("*************TrieTree Deletion: CASE 2************\n");
    printf("Trying to delete string '%s'.....\n", str[3]);
    if(delete(root, str[3]) > 0)
    {
        printf("String '%s' Deleted\n", str[3]);
        printf("Searching '%s' in TrieTree........\n", str[3]);
        if(search(root, str[3]) > 0)
        {
            printf("/'%s' found\n\n", str[3]);
        }
        else
        {
            printf("'%s' not found\n\n", str[3]);
        }
        printf("Searching '%s' in TrieTree........\n", str[1]);
        if(search(root, str[1]) > 0)
        {
            printf("/'%s' found\n\n", str[1]);
        }
        else
        {
            printf("'%s' not found\n\n", str[1]);
        }
    }
    else
    {
        printf("\n\nString '%s' not found", str[3]);
    }

    //Updation
    printf("****************TrieTree Updation****************\n");
    temp = update(root, str[4], str[6]);
    if(temp->isCompleteWord > 0)
    {
        printf("String '%s' Updated\n", str[4]);
        printf("Searching '%s' and %s in TrieTree........\n", str[4], str[6]);
        if(search(root, str[1]) > 0)
        {
            printf("'%s' not removed and updated\n\n", str[4]);
        }
        else
        {
            printf("'%s' removed and updated\n\n", str[4]);
        }
        if(search(root, str[6]) > 0)
        {
            printf("'%s' found\n\n", str[6]);
        }
        else
        {
            printf("'%s' not found\n\n", str[6]);
        }
    }
}
