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

int main()
{
    int ch;
    while (1)
    {
        printf("1. Append\n");
        printf("2. Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            exit(0);
            break;

        default:
            printf("Invalid choice........");
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
        temp = root;
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