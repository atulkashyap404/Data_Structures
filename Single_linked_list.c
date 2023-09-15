#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;

void append();
void addAtBegin();
void addAtAfter();
void delete();
void display();
int length();
void swapNodes();

void main()
{

    int ch, result;

    while (1)
    {
        printf("1. Append \n");
        printf("2. Add at begin \n");
        printf("3. Add at After \n");
        printf("4. Delete\n");
        printf("5. Display \n");
        printf("6. Length \n");
        printf("7. Swap Nodes \n");
        printf("8. Exit \n");

        printf("Enter the choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            addAtBegin();
            break;
        case 3:
            addAtAfter();
            break;
        case 4:
            delete ();
            break;
        case 5:
            display();
            break;
        case 6:
            result = length();
            printf("The length of the Single Linked List :  %d\n", result);
            break;
        case 7:
            swapNodes();
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("Invalid input...........");
        }
    }
}

void append()
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enthe the data in node : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void addAtBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Node data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {

        temp->link = root;
        root = temp;
    }
}

void addAtAfter()
{
    struct node *temp, *p;
    int loc, len, i = 1;
    printf("Enter the location : ");
    scanf("%d", &loc);
    len = length();
    if (loc > len)
    {
        printf("Invalid location\n");
        printf("Currently list is having %d nodes", len);
    }
    else
    {
        p = root;
        while (i < loc)
        {
            p = p->link;
            i++;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the node data : ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        temp->link = p->link;
        p->link = temp;
    }
}

void delete()
{
    struct node *temp;
    int loc;
    printf("Enter the location to delete : ");
    scanf("%d", &loc);
    if (loc > length())
    {
        printf("Invalid loaction\n");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node *p = root, *q;
        int i = 1;
        while (i < loc - 1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}

void display()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("List is empty \n\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

int length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    while (temp->link != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void swapNodes()
{
    struct node *p, *q, *r;
    int loc, i = 1;
    printf("Enter the location : ");
    scanf("%d", &loc);
    if (loc > length())
    {
        printf("Invalid lcation\n");
    }
    else
    {
        p = root;
        while (i < loc - 1)
        {
            p = p->link;
            i++;
        }

        q = p->link;
        r = q->link;

        q->link = r->link;
        r->link = q;
        p->link = r;
    }
}