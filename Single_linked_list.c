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
void deleteFirstNode();
void deleteSpecifiedNode();
void display();
void length();
void reverseList();
void swapTwoNodes();
void sortElements();

void main()
{

    int ch;

    while (1)
    {
        printf("1. Append \n");
        printf("2. Add at begin \n");
        printf("3. Add at After \n");
        printf("4. Delete First Node \n");
        printf("5. Delete Specified Node \n");
        printf("6. Display \n");
        printf("7. Length \n");
        printf("8. Reverse List\n");
        printf("9. Swap 2 Nodes \n");
        printf("10. Sort Elements \n");

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
            deleteFirstNode();
            break;
        case 5:
            deleteSpecifiedNode();
            break;
        case 6:
            display();
            break;
        case 7:
            length();
            break;
        case 8:
            reverseList();
            break;
        case 9:
            swapTwoNodes();
            break;
        case 10:
            sortElements();
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
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link=temp;
    }
}

void addAtBegin()
{
}

void addAtAfter()
{
}

void deleteFirstNode()
{
}

void deleteSpecifiedNode()
{
}

void display()
{
}

void length()
{
}

void reverseList()
{
}

void swapTwoNodes()
{
}

void sortElements()
{
}
