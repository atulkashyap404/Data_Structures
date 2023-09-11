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
        printf("7. Exit \n");

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
}

void delete()
{
}

void display()
{
    struct node* temp;
    temp=root;
    if(temp == NULL)
    {
        printf("List is empty \n\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
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