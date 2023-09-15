#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

void insert();
void delete();
void traverse();

int queue[CAPACITY];
int front = 0;
int rear = 0;

int main()
{
    int ch;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");

        printf("Enter the choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid input........\n\n");
            break;
        }
    }
}

void insert()
{
    int ele;
    if (CAPACITY == rear)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter the element : ");
        scanf("%d", &ele);
        queue[rear] = ele;
        rear++;
    }
}

void delete()
{

    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("deleted element : %d\n", queue[front]);
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void traverse()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue Elements\n");
        for (int i = front; i < rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}