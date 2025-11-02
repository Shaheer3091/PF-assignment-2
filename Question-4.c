#include <stdio.h>
void display()
{
    printf("\n===========================\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peek\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    printf("===========================\n");
}
void Push(int stack[], int *top, int maxSize)
{
    int val;
    if (*top == maxSize - 1)
    {
        printf("Stack is Full!. Can't Push More!\n");
    }
    else
    {
        printf("Enter Value to Push :");
        scanf("%d", &val);
        (*top)++;
        stack[*top] = val;
    }
}
void Pop(int stack[], int *top)
{
    int val;
    if (*top == -1)
    {
        printf("Stack is Totally Empty!.\n");
    }
    else
    {
        printf("Enter Value to Pop :");
        scanf("%d", &val);
        (*top)--;
    }
}
void Peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is Totally Empty!.\n");
    }
    else
    {
        printf("Top Stack Element is %d\n", stack[top]);
    }
}
void Display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is Totally Empty!.\n");
        return;
    }
    printf("\n===STACK===\n");
    for (int i = top; i >=0; i--)
    {
        printf("  -%d-\n", stack[i]);
    }
}
int main()
{
    int choice = 0;
    int maxSize = 10;
    int stack[maxSize];
    int top = -1;
    while (choice != 5)
    {
        display();
        printf("Enter Your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push(stack, &top, maxSize);
            break;
        case 2:
            Pop(stack, &top);
            break;
        case 3:
            Peek(stack, top);
            break;
        case 4:
            Display(stack, top);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
            break;
        default:
            printf("Invalid Choice!\n");
        }
    }
}