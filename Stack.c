/* Stack implementation using static Array*/
#include <stdio.h>
#include<stdlib.h>
#define CAPACITY 5

void push(int);
int isFull();
int pop();
int isEmpty();
void peek();
void traverse();

int stack[CAPACITY],
    top = -1;

void main()
{
    int ch, ele, item;

    while (1)
    {
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("4. Traverse \n");
        printf("5. Quit \n");

        printf("Enter the choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the elemnet to push in stack  :  ");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            item = pop();
            if (item == 0)
            {
                printf("Stack is Underflow \n");
            }
            else
            {
                printf("%d is popped element from stack", item);
            }
            break;
        case 3:
            peek();
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Invalid Input........\n\n");
        }
    }
}

void push(int ele)
{
    if (isFull())
    {
        printf("Stack is Full\n");
    }
    else
    {
        top++;
        stack[top] = ele;
        printf("%d element is pushed into Stack\n", ele);
    }
}

int isFull()
{

    if (top == CAPACITY - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{

    if (isEmpty())
    {

        return 0;
    }
    else
    {

        return stack[top--];
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty \n");
    }
    else
    {

        printf("peek element : %d \n", stack[top]);
    }
}

void traverse()
{
    int i;
    if (isEmpty())
    {
        printf("Stack is Empty no elemnets to print \n");
    }
    else
    {
        for(i=0;i<=top;i++){
            printf(" %d \n",stack[i]);
        }
    }
}