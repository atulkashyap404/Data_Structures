#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void append();
int length();
void display();
void addAtAfter();
void deleteNodeLoc();
void deleteNodeBegin();
void deleteNodeEnd();

int main()
{
    int ch, ans;
    while (1)
    {
        printf("1. Append\n");
        printf("2. Add At After\n");
        printf("3. Length\n");
        printf("4. Display\n");
        printf("5. Delete Node By Location\n");
        printf("6. Delete Node Begin\n");
        printf("7. Delete Node End\n");
        printf("8. Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            addAtAfter();
            break;
        case 3:
            ans = length();
            printf("List have nodes : %d\n", ans);
            break;
        case 4:
            display();
            break;
        case 5:
            deleteNodeLoc();
            break;
        case 6:
            deleteNodeBegin();
            break;
        case 7:
            deleteNodeEnd();
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("Invalid choice........\n\n");
            break;
        }
    }
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
}

int length()
{
    struct node *temp = root;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

void display()
{
    struct node *temp = root;
    if (temp == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->right;
        }
        printf("\n\n");
    }
}

void addAtAfter()
{
    struct node *temp, *p;
    int loc, len, i = 1;
    printf("Enter the location to add : ");
    scanf("%d", &loc);
    len = length();
    if (loc > len)
    {
        printf("Invalid location");
        printf("List cantain : %d nodes only\n", len);
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the node data : ");
        scanf("%d", &temp->data);
        temp->left = NULL;
        temp->right = NULL;
        p = root;
        while (i <= loc)
        {
            p = p->right;
            i++;
        }

        temp->right = p->right;
        p->right->left = temp;
        temp->left = p;
        p->right = temp;
    }
}

void deleteNodeLoc()
{
    struct node *p;
    int loc, len, i = 1;
    len = length();
    printf("Enter the Location : ");
    scanf("%d", &loc);
    if (loc > len)
    {
        printf("Invalid Location\n");
        printf("List having only %d length\n", len);
    }
    else
    {
        p = root;
        while (i < loc)
        {
            p = p->right;
            i++;
        }

        p->left->right = p->right;
        p->right->left = p->left;
        free(p);
    }
}

void deleteNodeBegin()
{
    struct node *temp;
    temp = root;
    if (root == NULL)
    {
        printf("List is Empty\n");
    }
    root = temp->right;
    temp->right->left = NULL;
}

void deleteNodeEnd()
{
    struct node *temp;
    temp = root;
    int len,i=1;
    len=length();
    if (root == NULL)
    {
        printf("List is Empty\n");
    }
    else{
        while (i<len-1)
        {
            temp=temp->right;
        }
        
        temp->right=NULL;
        
    }
}